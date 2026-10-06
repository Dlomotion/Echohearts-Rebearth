#!/usr/bin/env python3
"""Echohearts-Rebearth Unreal validation helper.

This script is intentionally conservative and does not claim runtime proof. It
validates the local engine root and project input, then prints the exact commands
required to perform the UE 5.8 editor build and automation steps.

Usage examples:
  python 09_Technical/Tools/verify_unreal_gate.py preflight --engine-root "C:/Program Files/Epic Games/UE_5.8"
  python 09_Technical/Tools/verify_unreal_gate.py build --engine-root "C:/Program Files/Epic Games/UE_5.8" --project "EchoheartsRebearth.uproject" --target EchoheartsRebearthEditor --platform Win64 --config Development
  python 09_Technical/Tools/verify_unreal_gate.py automation --engine-root "C:/Program Files/Epic Games/UE_5.8" --project "EchoheartsRebearth.uproject" --tests "Echohearts.Partners.CommandBuffer"
"""

from __future__ import annotations

import argparse
import os
import subprocess
import sys
from pathlib import Path


REPO_ROOT = Path(__file__).resolve().parents[2]
DEFAULT_PROJECT = REPO_ROOT / "EchoheartsRebearth.uproject"


def path_to_windows(value: str | None) -> str:
    if value is None:
        return ""
    p = Path(value)
    return str(p)


def check_path(label: str, value: Path, must_exist: bool = True) -> None:
    exists = value.exists() if value is not None else False
    if must_exist and not exists:
        raise FileNotFoundError(f"{label} not found: {value}")
    print(f"{label}: {'OK' if exists else 'MISSING'} -> {value}")


def get_unreal_paths(engine_root: str) -> dict[str, Path]:
    root = Path(engine_root).expanduser().resolve()
    return {
        "engine_root": root,
        "build_bat": root / "Engine" / "Build" / "BatchFiles" / "Build.bat",
        "uat_bat": root / "Engine" / "Build" / "BatchFiles" / "RunUAT.bat",
        "ubt_exe": root / "Engine" / "Binaries" / "DotNET" / "UnrealBuildTool" / "UnrealBuildTool.exe",
        "ue_editor": root / "Engine" / "Binaries" / "Win64" / "UnrealEditor-Cmd.exe",
        "editor_cmd": root / "Engine" / "Binaries" / "Win64" / "UnrealEditor-Cmd.exe",
    }


def preflight(engine_root: str, project_path: str | None = None) -> int:
    if not engine_root:
        raise ValueError("--engine-root is required for preflight.")

    root = Path(engine_root).expanduser().resolve()
    if not root.exists():
        raise FileNotFoundError(f"Engine root does not exist: {root}")

    paths = get_unreal_paths(str(root))
    for key, value in paths.items():
        check_path(key, value)

    project = Path(project_path).expanduser().resolve() if project_path else DEFAULT_PROJECT
    check_path("project", project)

    check_path("editor_target", project.parent / "Source" / "EchoheartsRebearthEditor.Target.cs")
    check_path("game_target", project.parent / "Source" / "EchoheartsRebearth.Target.cs")
    check_path("module_rules", project.parent / "Source" / "Echohearts" / "Echohearts.Build.cs")
    print("\nPath checks complete; compilation and runtime remain unverified.")
    return 0


def _run(cmd: list[str], cwd: str | None = None) -> int:
    print("\nExecuting:")
    print(" ".join(cmd))
    if cwd is not None:
        print(f"cwd={cwd}")
    result = subprocess.run(cmd, cwd=cwd)
    return result.returncode


def build(engine_root: str, project_path: str | None, target: str, platform: str, config: str) -> int:
    if not engine_root:
        raise ValueError("--engine-root is required for build.")

    root = Path(engine_root).expanduser().resolve()
    project = Path(project_path).expanduser().resolve() if project_path else DEFAULT_PROJECT
    check_path("engine_root", root)
    check_path("project", project)

    build_bat = root / "Engine" / "Build" / "BatchFiles" / "Build.bat"
    if not build_bat.exists():
        raise FileNotFoundError(f"Build script not found: {build_bat}")

    cmd = [
        str(build_bat),
        "-Project=" + str(project),
        "-Target=" + target,
        "-Platform=" + platform,
        "-Configuration=" + config,
    ]
    return _run(cmd, cwd=str(REPO_ROOT))


def automation(engine_root: str, project_path: str | None, tests: str) -> int:
    if not engine_root:
        raise ValueError("--engine-root is required for automation.")

    root = Path(engine_root).expanduser().resolve()
    project = Path(project_path).expanduser().resolve() if project_path else DEFAULT_PROJECT
    check_path("engine_root", root)
    check_path("project", project)

    editor = root / "Engine" / "Binaries" / "Win64" / "UnrealEditor-Cmd.exe"
    if not editor.exists():
        raise FileNotFoundError(f"UnrealEditor-Cmd.exe not found: {editor}")

    cmd = [
        str(editor),
        str(project),
        "-ExecCmds=Automation RunTests " + tests,
        "-Unattended",
        "-NullRHI",
    ]
    return _run(cmd, cwd=str(REPO_ROOT))


def package(engine_root: str, project_path: str | None, config: str, output_dir: str | None) -> int:
    if not engine_root:
        raise ValueError("--engine-root is required for packaging.")

    root = Path(engine_root).expanduser().resolve()
    project = Path(project_path).expanduser().resolve() if project_path else DEFAULT_PROJECT
    check_path("engine_root", root)
    check_path("project", project)

    uat = root / "Engine" / "Build" / "BatchFiles" / "RunUAT.bat"
    if not uat.exists():
        raise FileNotFoundError(f"RunUAT.bat not found: {uat}")

    out_dir = Path(output_dir) if output_dir else REPO_ROOT / "PackagedOutput"
    out_dir.mkdir(parents=True, exist_ok=True)

    cmd = [
        str(uat),
        "BuildCookRun",
        "-project=" + str(project),
        "-noP4",
        "-platform=Win64",
        "-clientconfig=" + config,
        "-serverconfig=" + config,
        "-cook",
        "-allmaps",
        "-build",
        "-stage",
        "-pak",
        "-archive",
        "-archivedirectory=" + str(out_dir),
    ]
    return _run(cmd, cwd=str(REPO_ROOT))


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Echohearts-Rebearth Unreal gate validator")
    subparsers = parser.add_subparsers(dest="command", required=True)

    pre = subparsers.add_parser("preflight", help="Validate an authorized UE 5.8 root and project file")
    pre.add_argument("--engine-root", required=True, help="Absolute path to the UE 5.8 root, e.g. C:/Program Files/Epic Games/UE_5.8")
    pre.add_argument("--project", default=str(DEFAULT_PROJECT), help="Optional project path")
    pre.set_defaults(func=lambda ns: preflight(ns.engine_root, ns.project))

    b = subparsers.add_parser("build", help="Print and optionally run the EchoheartsRebearthEditor build command")
    b.add_argument("--engine-root", required=True)
    b.add_argument("--project", default=str(DEFAULT_PROJECT))
    b.add_argument("--target", default="EchoheartsRebearthEditor")
    b.add_argument("--platform", default="Win64")
    b.add_argument("--config", default="Development")
    b.add_argument("--execute", action="store_true", help="Actually run the generated build command")
    b.set_defaults(func=lambda ns: (build(ns.engine_root, ns.project, ns.target, ns.platform, ns.config) if ns.execute else print_build_command(ns.engine_root, ns.project, ns.target, ns.platform, ns.config)))

    a = subparsers.add_parser("automation", help="Print and optionally run the Automation RunTests command")
    a.add_argument("--engine-root", required=True)
    a.add_argument("--project", default=str(DEFAULT_PROJECT))
    a.add_argument("--tests", default="Echohearts.Partners.CommandBuffer")
    a.add_argument("--execute", action="store_true")
    a.set_defaults(func=lambda ns: (automation(ns.engine_root, ns.project, ns.tests) if ns.execute else print_automation_command(ns.engine_root, ns.project, ns.tests)))

    p = subparsers.add_parser("package", help="Print and optionally run the BuildCookRun packaging command")
    p.add_argument("--engine-root", required=True)
    p.add_argument("--project", default=str(DEFAULT_PROJECT))
    p.add_argument("--config", default="Development")
    p.add_argument("--output-dir", default=str(REPO_ROOT / "PackagedOutput"))
    p.add_argument("--execute", action="store_true")
    p.set_defaults(func=lambda ns: (package(ns.engine_root, ns.project, ns.config, ns.output_dir) if ns.execute else print_package_command(ns.engine_root, ns.project, ns.config, ns.output_dir)))

    return parser.parse_args()


def print_build_command(engine_root: str, project_path: str, target: str, platform: str, config: str) -> int:
    project = Path(project_path).expanduser().resolve() if project_path else DEFAULT_PROJECT
    build_bat = Path(engine_root).expanduser().resolve() / "Engine" / "Build" / "BatchFiles" / "Build.bat"
    print("\nBuild command to execute:")
    print(f'"{build_bat}" -Project="{project}" -Target="{target}" -Platform="{platform}" -Configuration="{config}"')
    return 0


def print_automation_command(engine_root: str, project_path: str, tests: str) -> int:
    project = Path(project_path).expanduser().resolve() if project_path else DEFAULT_PROJECT
    editor = Path(engine_root).expanduser().resolve() / "Engine" / "Binaries" / "Win64" / "UnrealEditor-Cmd.exe"
    print("\nAutomation command to execute:")
    print(f'"{editor}" "{project}" -ExecCmds="Automation RunTests {tests}" -Unattended -NullRHI')
    return 0


def print_package_command(engine_root: str, project_path: str, config: str, output_dir: str) -> int:
    project = Path(project_path).expanduser().resolve() if project_path else DEFAULT_PROJECT
    uat = Path(engine_root).expanduser().resolve() / "Engine" / "Build" / "BatchFiles" / "RunUAT.bat"
    out_dir = Path(output_dir).expanduser().resolve()
    print("\nPackaging command to execute:")
    print(
        f'"{uat}" BuildCookRun -project="{project}" -noP4 -platform=Win64 -clientconfig={config} -serverconfig={config} -cook -allmaps -build -stage -pak -archive -archivedirectory="{out_dir}"'
    )
    return 0


if __name__ == "__main__":
    args = parse_args()
    try:
        rc = args.func(args)
        sys.exit(rc if isinstance(rc, int) else 0)
    except Exception as exc:  # pragma: no cover - CLI behaviour is intentionally explicit
        print(f"ERROR: {exc}", file=sys.stderr)
        sys.exit(1)
