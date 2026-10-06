#!/usr/bin/env python3
"""Echohearts: Rebearth Unreal Engine 5.8 compiler driver.

This is a project-specific build driver, not a replacement C++ compiler.
UnrealBuildTool remains responsible for C++ compilation, UnrealHeaderTool,
module/target evaluation, and platform compiler selection.
"""
from __future__ import annotations

import argparse
import json
import os
import re
import subprocess
import sys
from dataclasses import dataclass
from datetime import datetime, timezone
from pathlib import Path
from typing import Sequence

ENGINE_MAJOR = 5
ENGINE_MINOR = 8
PROJECT_FILE = "EchoheartsRebearth.uproject"
GAME_TARGET = "EchoheartsRebearth"
EDITOR_TARGET = "EchoheartsRebearthEditor"
RUNTIME_MODULE = "Echohearts"

REQUIRED_REPO_PATHS = (
    PROJECT_FILE,
    ".github/workflows/infrastructure.yml",
    "09_Technical/Tools/verify_infrastructure.py",
    "Source/EchoheartsRebearth.Target.cs",
    "Source/EchoheartsRebearthEditor.Target.cs",
    "Source/Echohearts/Echohearts.Build.cs",
    "Source/Echohearts/Public/Echohearts.h",
    "Source/Echohearts/Private/EchoheartsModule.cpp",
)

BANNED_ACTIVE_TOKENS = (
    "UE4Editor.exe",
    'EngineAssociation": "5.4',
)

MAP_RE = re.compile(r"^/Game/(?:[A-Za-z0-9_]+/)*[A-Za-z0-9_]+$")
WORKFLOW_PYTHON_COMMAND_RE = re.compile(
    r"^\s*run:\s*python(?:3)?\s+([^\s]+\.py)(?:\s|$)", re.MULTILINE
)


class CompilerGateError(RuntimeError):
    pass


@dataclass(frozen=True)
class UnrealTools:
    build: Path
    uat: Path
    editor_cmd: Path


def utc_now() -> str:
    return datetime.now(timezone.utc).isoformat()


def default_repo_root() -> Path:
    script = Path(__file__).resolve()
    for parent in script.parents:
        if (parent / PROJECT_FILE).is_file():
            return parent
    return script.parents[1]


def run_command(command: Sequence[str], cwd: Path, log_path: Path | None = None) -> int:
    printable = " ".join(str(part) for part in command)
    print(f"$ {printable}")
    completed = subprocess.run(
        [str(part) for part in command],
        cwd=str(cwd),
        text=True,
        stdout=subprocess.PIPE,
        stderr=subprocess.STDOUT,
        check=False,
    )
    output = completed.stdout or ""
    if output:
        print(output, end="" if output.endswith("\n") else "\n")
    if log_path is not None:
        log_path.parent.mkdir(parents=True, exist_ok=True)
        log_path.write_text(output, encoding="utf-8")
    return completed.returncode


def git_head(repo_root: Path) -> str:
    try:
        result = subprocess.run(
            ["git", "rev-parse", "HEAD"],
            cwd=str(repo_root),
            text=True,
            stdout=subprocess.PIPE,
            stderr=subprocess.DEVNULL,
            check=False,
        )
        if result.returncode == 0:
            return result.stdout.strip()
    except OSError:
        pass
    return "UNKNOWN"


def load_json(path: Path) -> dict:
    try:
        return json.loads(path.read_text(encoding="utf-8-sig"))
    except (OSError, json.JSONDecodeError) as exc:
        raise CompilerGateError(f"Invalid JSON: {path}: {exc}") from exc


def validate_repository(repo_root: Path) -> list[str]:
    errors: list[str] = []
    for relative in REQUIRED_REPO_PATHS:
        if not (repo_root / relative).is_file():
            errors.append(f"Missing required file: {relative}")

    project_path = repo_root / PROJECT_FILE
    if project_path.is_file():
        try:
            project = load_json(project_path)
            if str(project.get("EngineAssociation")) != f"{ENGINE_MAJOR}.{ENGINE_MINOR}":
                errors.append("EchoheartsRebearth.uproject must declare EngineAssociation 5.8")
            modules = {
                item.get("Name")
                for item in project.get("Modules", [])
                if isinstance(item, dict)
            }
            if RUNTIME_MODULE not in modules:
                errors.append(f".uproject must declare runtime module {RUNTIME_MODULE}")
        except CompilerGateError as exc:
            errors.append(str(exc))

    target_expectations = {
        "Source/EchoheartsRebearth.Target.cs": (
            "class EchoheartsRebearthTarget",
            'ExtraModuleNames.Add("Echohearts")',
        ),
        "Source/EchoheartsRebearthEditor.Target.cs": (
            "class EchoheartsRebearthEditorTarget",
            'ExtraModuleNames.Add("Echohearts")',
        ),
        "Source/Echohearts/Echohearts.Build.cs": (
            "class Echohearts : ModuleRules",
        ),
    }
    for relative, expected_tokens in target_expectations.items():
        path = repo_root / relative
        if not path.is_file():
            continue
        text_value = path.read_text(encoding="utf-8-sig", errors="replace")
        for token in expected_tokens:
            if token not in text_value:
                errors.append(f"{relative} missing expected contract: {token}")

    active_candidates = [
        repo_root / "BuildScripts" / "BuildFoundation.ps1",
        repo_root / "package_unreal.ps1",
        repo_root / "09_Technical" / "Tools" / "verify_unreal_gate.py",
    ]
    for path in active_candidates:
        if not path.is_file():
            continue
        text_value = path.read_text(encoding="utf-8-sig", errors="replace")
        for banned in BANNED_ACTIVE_TOKENS:
            if banned in text_value:
                errors.append(f"Stale UE contract in {path.relative_to(repo_root)}: {banned}")

    workflow_path = repo_root / ".github" / "workflows" / "infrastructure.yml"
    if workflow_path.is_file():
        workflow = workflow_path.read_text(encoding="utf-8-sig", errors="replace")
        for script in WORKFLOW_PYTHON_COMMAND_RE.findall(workflow):
            if not (repo_root / script).is_file():
                errors.append(
                    f"Infrastructure workflow references missing Python script: {script}"
                )

    return errors


def resolve_unreal_tools(engine_root: Path) -> UnrealTools:
    version_path = engine_root / "Engine" / "Build" / "Build.version"
    if not version_path.is_file():
        raise CompilerGateError(f"Unreal Build.version not found: {version_path}")
    version = load_json(version_path)
    if version.get("MajorVersion") != ENGINE_MAJOR or version.get("MinorVersion") != ENGINE_MINOR:
        raise CompilerGateError(
            f"UE {ENGINE_MAJOR}.{ENGINE_MINOR} required; Build.version reports "
            f"{version.get('MajorVersion')}.{version.get('MinorVersion')}"
        )

    if os.name != "nt":
        raise CompilerGateError(
            "Executable build orchestration is currently gated to Windows x64. "
            "Repository checks are host-neutral; Linux/macOS adapters require target-host evidence."
        )

    tools = UnrealTools(
        build=engine_root / "Engine" / "Build" / "BatchFiles" / "Build.bat",
        uat=engine_root / "Engine" / "Build" / "BatchFiles" / "RunUAT.bat",
        editor_cmd=engine_root / "Engine" / "Binaries" / "Win64" / "UnrealEditor-Cmd.exe",
    )
    for label, path in (
        ("Build.bat", tools.build),
        ("RunUAT.bat", tools.uat),
        ("UnrealEditor-Cmd.exe", tools.editor_cmd),
    ):
        if not path.is_file():
            raise CompilerGateError(f"{label} not found: {path}")
    return tools


def map_asset_path(repo_root: Path, map_package: str) -> Path:
    if not MAP_RE.fullmatch(map_package):
        raise CompilerGateError(
            "Map package must look like /Game/Maps/Name using letters, digits, and underscores"
        )
    relative = map_package.removeprefix("/Game/") + ".umap"
    path = repo_root / "Content" / relative
    if not path.is_file():
        raise CompilerGateError(f"Authored map does not exist: {path}")
    return path


def write_manifest(evidence_dir: Path, payload: dict) -> None:
    evidence_dir.mkdir(parents=True, exist_ok=True)
    (evidence_dir / "compiler-manifest.json").write_text(
        json.dumps(payload, indent=2, sort_keys=True), encoding="utf-8"
    )


def command_repo_check(args: argparse.Namespace) -> int:
    repo_root = Path(args.repo_root).resolve()
    errors = validate_repository(repo_root)
    result = {
        "tool": "EchoheartsCompiler",
        "scope": "repository-contract",
        "engine_target": "5.8",
        "runtime_module": RUNTIME_MODULE,
        "source_commit": git_head(repo_root),
        "status": "REPOSITORY_CONTRACT_VALID" if not errors else "FAILED",
        "runtime_verified": False,
        "errors": errors,
        "timestamp_utc": utc_now(),
    }
    print(json.dumps(result, indent=2))
    return 0 if not errors else 1


def require_preflight(args: argparse.Namespace) -> tuple[Path, Path, UnrealTools, Path]:
    repo_root = Path(args.repo_root).resolve()
    errors = validate_repository(repo_root)
    if errors:
        raise CompilerGateError("Repository contract failed:\n- " + "\n- ".join(errors))

    engine_root_text = args.engine_root or os.environ.get("UE_ROOT")
    if not engine_root_text:
        raise CompilerGateError("Provide --engine-root or set UE_ROOT to the Unreal Engine 5.8 root")

    engine_root = Path(engine_root_text).expanduser().resolve()
    tools = resolve_unreal_tools(engine_root)
    project = repo_root / PROJECT_FILE
    return repo_root, engine_root, tools, project


def command_preflight(args: argparse.Namespace) -> int:
    repo_root, engine_root, tools, project = require_preflight(args)
    lfs_rc = run_command(["git", "lfs", "fsck"], repo_root)
    if lfs_rc != 0:
        raise CompilerGateError(f"git lfs fsck failed with exit code {lfs_rc}")

    print(json.dumps({
        "tool": "EchoheartsCompiler",
        "status": "PREFLIGHT_PASSED",
        "runtime_verified": False,
        "repo_root": str(repo_root),
        "engine_root": str(engine_root),
        "project": str(project),
        "build_tool": str(tools.build),
        "uat": str(tools.uat),
        "editor_cmd": str(tools.editor_cmd),
        "source_commit": git_head(repo_root),
        "timestamp_utc": utc_now(),
    }, indent=2))
    return 0


def command_build(args: argparse.Namespace) -> int:
    repo_root, _, tools, project = require_preflight(args)
    evidence = repo_root / args.evidence_dir
    command = [
        str(tools.build),
        EDITOR_TARGET,
        args.platform,
        args.configuration,
        f"-Project={project}",
        "-WaitMutex",
        "-NoHotReloadFromIDE",
    ]
    rc = run_command(command, repo_root, evidence / "compile.log")
    write_manifest(evidence, {
        "tool": "EchoheartsCompiler",
        "stage": "build",
        "command_exit_code": rc,
        "source_commit": git_head(repo_root),
        "status": "BUILD_COMMAND_SUCCEEDED" if rc == 0 else "BUILD_COMMAND_FAILED",
        "runtime_verified": False,
        "timestamp_utc": utc_now(),
    })
    return rc


def command_automation(args: argparse.Namespace) -> int:
    repo_root, _, tools, project = require_preflight(args)
    evidence = repo_root / args.evidence_dir
    report = evidence / "Automation"
    report.mkdir(parents=True, exist_ok=True)
    command = [
        str(tools.editor_cmd),
        str(project),
        "-Unattended",
        "-NoP4",
        "-NoSplash",
        "-NullRHI",
        f"-ExecCmds=Automation RunTests {args.tests}",
        "-TestExit=Automation Test Queue Empty",
        f"-ReportExportPath={report}",
    ]
    rc = run_command(command, repo_root, evidence / "automation.log")
    write_manifest(evidence, {
        "tool": "EchoheartsCompiler",
        "stage": "automation",
        "test_filter": args.tests,
        "command_exit_code": rc,
        "source_commit": git_head(repo_root),
        "status": "AUTOMATION_PROCESS_SUCCEEDED" if rc == 0 else "AUTOMATION_PROCESS_FAILED",
        "test_results_require_review": True,
        "runtime_verified": False,
        "timestamp_utc": utc_now(),
    })
    return rc


def command_package(args: argparse.Namespace) -> int:
    repo_root, _, tools, project = require_preflight(args)
    map_asset_path(repo_root, args.map)
    evidence = repo_root / args.evidence_dir
    output = repo_root / args.output_dir

    if output.exists() and (not output.is_dir() or any(output.iterdir())):
        raise CompilerGateError(f"Package output must be an empty directory or absent: {output}")
    output.mkdir(parents=True, exist_ok=True)

    command = [
        str(tools.uat),
        "BuildCookRun",
        f"-project={project}",
        "-noP4",
        "-unattended",
        f"-target={GAME_TARGET}",
        f"-platform={args.platform}",
        f"-clientconfig={args.configuration}",
        f"-map={args.map}",
        "-build",
        "-cook",
        "-stage",
        "-pak",
        "-package",
        "-archive",
        f"-archivedirectory={output}",
    ]
    rc = run_command(command, repo_root, evidence / "package.log")
    write_manifest(evidence, {
        "tool": "EchoheartsCompiler",
        "stage": "package",
        "map": args.map,
        "command_exit_code": rc,
        "source_commit": git_head(repo_root),
        "status": "PACKAGE_COMMAND_SUCCEEDED" if rc == 0 else "PACKAGE_COMMAND_FAILED",
        "package_launch_verified": False,
        "runtime_verified": False,
        "timestamp_utc": utc_now(),
    })
    return rc


def make_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(
        prog="EchoheartsCompiler",
        description=(
            "Project-specific UE5.8 compiler/build driver for Echohearts: Rebearth. "
            "It delegates C++ compilation to UnrealBuildTool."
        ),
    )
    parser.add_argument("--repo-root", default=str(default_repo_root()))
    parser.add_argument("--engine-root", default=None)
    parser.add_argument("--evidence-dir", default="BuildEvidence/Compiler")
    sub = parser.add_subparsers(dest="command", required=True)

    repo = sub.add_parser("repo-check", help="Validate source/module/target contracts without Unreal installed")
    repo.set_defaults(func=command_repo_check)

    pre = sub.add_parser("preflight", help="Validate repository and exact UE5.8 toolchain paths")
    pre.set_defaults(func=command_preflight)

    build = sub.add_parser("build", help="Compile the Development Editor target through UnrealBuildTool")
    build.add_argument("--configuration", default="Development")
    build.add_argument("--platform", default="Win64")
    build.set_defaults(func=command_build)

    auto = sub.add_parser("automation", help="Run an Unreal Automation test filter and retain the report")
    auto.add_argument("--tests", default="Echohearts.")
    auto.set_defaults(func=command_automation)

    package = sub.add_parser("package", help="Cook/package one authored map through AutomationTool")
    package.add_argument("--configuration", default="Development")
    package.add_argument("--platform", default="Win64")
    package.add_argument("--map", required=True)
    package.add_argument("--output-dir", default="PackagedOutput")
    package.set_defaults(func=command_package)

    return parser


def main() -> int:
    parser = make_parser()
    args = parser.parse_args()
    try:
        rc = args.func(args)
        return int(rc or 0)
    except CompilerGateError as exc:
        print(f"ERROR: {exc}", file=sys.stderr)
        return 1
    except KeyboardInterrupt:
        print("ERROR: interrupted", file=sys.stderr)
        return 130


if __name__ == "__main__":
    raise SystemExit(main())
