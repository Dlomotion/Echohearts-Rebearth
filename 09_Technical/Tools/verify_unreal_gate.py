#!/usr/bin/env python3
"""Fail-closed UE 5.8 workflow helper for Echohearts: Rebearth."""

from __future__ import annotations

import argparse
import datetime as dt
import hashlib
import json
import os
import shlex
import subprocess
import sys
from pathlib import Path
from typing import Sequence

REPO_ROOT = Path(__file__).resolve().parents[2]
DEFAULT_PROJECT = REPO_ROOT / "EchoheartsRebearth.uproject"
NOT_VERIFIED = "NOT YET VERIFIED — UE BUILD/RUNTIME EVIDENCE REQUIRED"
CONFIGS = ("DebugGame", "Development", "Shipping", "Test")
PLATFORMS = ("Win64", "Linux", "Mac", "Android", "IOS")


def utc_now() -> str:
    return dt.datetime.now(dt.timezone.utc).isoformat()


def sha256(path: Path) -> str:
    digest = hashlib.sha256()
    with path.open("rb") as stream:
        for chunk in iter(lambda: stream.read(1024 * 1024), b""):
            digest.update(chunk)
    return digest.hexdigest()


def git_value(*args: str) -> str | None:
    result = subprocess.run(["git", *args], cwd=REPO_ROOT, capture_output=True, text=True, check=False)
    return result.stdout.strip() if result.returncode == 0 else None


def get_project(value: str | None) -> Path:
    return Path(value).expanduser().resolve() if value else DEFAULT_PROJECT.resolve()


def paths(engine_root: str) -> dict[str, Path]:
    root = Path(engine_root).expanduser().resolve()
    win64 = root / "Engine" / "Binaries" / "Win64"
    return {
        "root": root,
        "build": root / "Engine" / "Build" / "BatchFiles" / "Build.bat",
        "uat": root / "Engine" / "Build" / "BatchFiles" / "RunUAT.bat",
        "editor": win64 / "UnrealEditor.exe",
        "editor_cmd": win64 / "UnrealEditor-Cmd.exe",
    }


def require_file(label: str, path: Path) -> None:
    if not path.is_file():
        raise FileNotFoundError(f"{label} not found: {path}")
    print(f"{label}: OK -> {path}")


def contract(project: Path) -> list[str]:
    require_file("project", project)
    try:
        descriptor = json.loads(project.read_text(encoding="utf-8-sig"))
    except (OSError, UnicodeError, json.JSONDecodeError) as exc:
        raise ValueError(f"invalid descriptor: {exc}") from exc
    if not isinstance(descriptor, dict):
        raise ValueError("descriptor root must be an object")
    association = str(descriptor.get("EngineAssociation", ""))
    if not association.startswith("5.8"):
        raise ValueError(f"EngineAssociation must target 5.8, found {association!r}")
    modules = descriptor.get("Modules")
    if not isinstance(modules, list) or not modules:
        raise ValueError("descriptor has no declared runtime module")
    source = project.parent / "Source"
    game_targets = [path for path in source.glob("*.Target.cs") if not path.name.endswith("Editor.Target.cs")]
    editor_targets = list(source.glob("*Editor.Target.cs"))
    if not game_targets:
        raise FileNotFoundError(f"no game Target.cs found under {source}")
    if not editor_targets:
        raise FileNotFoundError(f"no editor Target.cs found under {source}")
    print(f"game targets: {', '.join(path.name for path in game_targets)}")
    print(f"editor targets: {', '.join(path.name for path in editor_targets)}")
    names: list[str] = []
    for module in modules:
        if not isinstance(module, dict) or not isinstance(module.get("Name"), str):
            raise ValueError("every module requires a string Name")
        name = module["Name"]
        names.append(name)
        require_file(f"{name} Build.cs", source / name / f"{name}.Build.cs")
    print(f"descriptor_sha256: {sha256(project)}")
    print(f"modules: {', '.join(names)}")
    return names


def command_text(command: Sequence[str]) -> str:
    return subprocess.list2cmdline(list(command)) if os.name == "nt" else shlex.join(command)


def run_gate(gate: str, command: list[str], execute: bool, evidence_dir: str | None, cwd: Path) -> int:
    print(f"gate: {gate}\ncommand: {command_text(command)}\ncwd: {cwd}")
    if not execute:
        print(NOT_VERIFIED)
        return 0
    started = utc_now()
    result = subprocess.run(command, cwd=cwd, check=False)
    record = {
        "schemaVersion": 1,
        "gate": gate,
        "status": "PASS" if result.returncode == 0 else "FAIL",
        "command": command,
        "cwd": str(cwd),
        "startUtc": started,
        "endUtc": utc_now(),
        "exitCode": result.returncode,
        "repository": git_value("remote", "get-url", "origin"),
        "revision": git_value("rev-parse", "HEAD"),
        "workingTree": git_value("status", "--short"),
    }
    if evidence_dir:
        destination = Path(evidence_dir).expanduser().resolve()
        destination.mkdir(parents=True, exist_ok=True)
        out = destination / f"{gate.replace(' ', '-').lower()}.json"
        out.write_text(json.dumps(record, indent=2) + "\n", encoding="utf-8")
        print(f"evidence: {out}")
    print(json.dumps(record, indent=2))
    return result.returncode


def preflight(ns: argparse.Namespace) -> int:
    engine = paths(ns.engine_root)
    for label in ("build", "uat", "editor", "editor_cmd"):
        require_file(label, engine[label])
    contract(get_project(ns.project))
    print("PREFLIGHT PASSED (static project/toolchain scope only)")
    print(NOT_VERIFIED)
    return 0


def contract_command(ns: argparse.Namespace) -> int:
    contract(get_project(ns.project))
    print("REPOSITORY CONTRACT PASSED")
    print(NOT_VERIFIED)
    return 0


def generate(ns: argparse.Namespace) -> int:
    project = get_project(ns.project)
    contract(project)
    script = paths(ns.engine_root)["build"]
    require_file("Build.bat", script)
    return run_gate("project generation", [str(script), "-projectfiles", f"-project={project}", "-game", "-engine"], ns.execute, ns.evidence_dir, project.parent)


def build(ns: argparse.Namespace) -> int:
    project = get_project(ns.project)
    contract(project)
    script = paths(ns.engine_root)["build"]
    require_file("Build.bat", script)
    command = [str(script), ns.target, ns.platform, ns.config, str(project), "-WaitMutex", "-FromMsBuild"]
    return run_gate(f"build {ns.target} {ns.platform} {ns.config}", command, ns.execute, ns.evidence_dir, project.parent)


def editor(ns: argparse.Namespace) -> int:
    project = get_project(ns.project)
    contract(project)
    executable = paths(ns.engine_root)["editor"]
    require_file("UnrealEditor.exe", executable)
    command = [str(executable), str(project)] + ([ns.map] if ns.map else []) + ["-log"]
    return run_gate("editor launch", command, ns.execute, ns.evidence_dir, project.parent)


def automation(ns: argparse.Namespace) -> int:
    project = get_project(ns.project)
    contract(project)
    executable = paths(ns.engine_root)["editor_cmd"]
    require_file("UnrealEditor-Cmd.exe", executable)
    report = Path(ns.report_dir).expanduser().resolve() if ns.report_dir else project.parent / "Saved" / "AutomationReports"
    command = [str(executable), str(project), f"-ExecCmds=Automation RunTests {ns.tests};Quit", "-Unattended", "-NullRHI", "-TestExit=Automation Test Queue Empty", f"-ReportExportPath={report}", "-log"]
    return run_gate("automation", command, ns.execute, ns.evidence_dir, project.parent)


def package(ns: argparse.Namespace) -> int:
    project = get_project(ns.project)
    contract(project)
    script = paths(ns.engine_root)["uat"]
    require_file("RunUAT.bat", script)
    output = Path(ns.output_dir).expanduser().resolve()
    command = [str(script), "BuildCookRun", f"-project={project}", "-noP4", f"-platform={ns.platform}", f"-clientconfig={ns.config}", "-build", "-cook", "-stage", "-pak", "-archive", f"-archivedirectory={output}", "-utf8output", f"-map={ns.maps}" if ns.maps else "-allmaps"]
    return run_gate(f"package {ns.platform} {ns.config}", command, ns.execute, ns.evidence_dir, project.parent)


def execution_options(parser: argparse.ArgumentParser) -> None:
    parser.add_argument("--execute", action="store_true")
    parser.add_argument("--evidence-dir")


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Echohearts UE 5.8 evidence-gate helper")
    commands = parser.add_subparsers(dest="command", required=True)
    pre = commands.add_parser("preflight")
    pre.add_argument("--engine-root", required=True)
    pre.add_argument("--project", default=str(DEFAULT_PROJECT))
    pre.set_defaults(func=preflight)
    con = commands.add_parser("contract")
    con.add_argument("--project", default=str(DEFAULT_PROJECT))
    con.set_defaults(func=contract_command)
    gen = commands.add_parser("generate")
    gen.add_argument("--engine-root", required=True)
    gen.add_argument("--project", default=str(DEFAULT_PROJECT))
    execution_options(gen)
    gen.set_defaults(func=generate)
    bld = commands.add_parser("build")
    bld.add_argument("--engine-root", required=True)
    bld.add_argument("--project", default=str(DEFAULT_PROJECT))
    bld.add_argument("--target", required=True)
    bld.add_argument("--platform", default="Win64", choices=PLATFORMS)
    bld.add_argument("--config", default="Development", choices=CONFIGS)
    execution_options(bld)
    bld.set_defaults(func=build)
    edit = commands.add_parser("editor")
    edit.add_argument("--engine-root", required=True)
    edit.add_argument("--project", default=str(DEFAULT_PROJECT))
    edit.add_argument("--map")
    execution_options(edit)
    edit.set_defaults(func=editor)
    auto = commands.add_parser("automation")
    auto.add_argument("--engine-root", required=True)
    auto.add_argument("--project", default=str(DEFAULT_PROJECT))
    auto.add_argument("--tests", default="Echohearts.Partners.CommandBuffer")
    auto.add_argument("--report-dir")
    execution_options(auto)
    auto.set_defaults(func=automation)
    pack = commands.add_parser("package")
    pack.add_argument("--engine-root", required=True)
    pack.add_argument("--project", default=str(DEFAULT_PROJECT))
    pack.add_argument("--platform", default="Win64", choices=PLATFORMS)
    pack.add_argument("--config", default="Development", choices=CONFIGS)
    pack.add_argument("--maps")
    pack.add_argument("--output-dir", default=str(REPO_ROOT / "PackagedOutput"))
    execution_options(pack)
    pack.set_defaults(func=package)
    return parser.parse_args()


def main() -> int:
    args = parse_args()
    try:
        result = args.func(args)
        return result if isinstance(result, int) else 0
    except Exception as exc:
        print(f"BLOCKED: {exc}", file=sys.stderr)
        print(NOT_VERIFIED, file=sys.stderr)
        return 2


if __name__ == "__main__":
    raise SystemExit(main())
