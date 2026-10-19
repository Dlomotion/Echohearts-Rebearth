#!/usr/bin/env python3
"""Read-only Echohearts UE5.8 infrastructure validation. No runtime verification."""
import argparse
import json
from pathlib import Path

EXPECTED_MODULE = "Echohearts"

def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument("step", choices=["infrastructure", "recovery-plan"])
    args = p.parse_args()

    if args.step == "recovery-plan":
        print(json.dumps({
            "status": "PLAN_ONLY",
            "profiles": [
                {"latency_ms": ms, "loss_fraction": loss, "result": "NOT_RUN"}
                for ms, loss in [(150, .01), (250, .03), (350, .05)]
            ],
            "latency_definition": "UNRESOLVED: RTT or one-way",
            "acceptance_thresholds": "NOT_DEFINED",
            "ECO-API-001": "BLOCKED"
        }, indent=2))
        return 0

    root = Path(__file__).resolve().parents[2]
    required = [
        ".gitignore",
        ".gitattributes",
        "EchoheartsRebearth.uproject",
        "package_unreal.ps1",
        "Source/EchoheartsRebearth.Target.cs",
        "Source/EchoheartsRebearthEditor.Target.cs",
        "Source/Echohearts/Echohearts.Build.cs",
        "Source/Echohearts/Public/Echohearts.h",
        "Source/Echohearts/Private/EchoheartsModule.cpp",
    ]
    errors = ["Missing: " + f for f in required if not (root / f).is_file()]

    descriptor = root / "EchoheartsRebearth.uproject"
    if descriptor.is_file():
        try:
            data = json.loads(descriptor.read_text(encoding="utf-8-sig"))
            if str(data.get("EngineAssociation")) != "5.8":
                errors.append("Project must declare engine 5.8")
            modules = {
                m.get("Name") for m in data.get("Modules", [])
                if isinstance(m, dict)
            }
            if EXPECTED_MODULE not in modules:
                errors.append(f"Project must declare runtime module {EXPECTED_MODULE}")
        except (ValueError, AttributeError, OSError):
            errors.append("Invalid project JSON")

    targets = {
        "Source/EchoheartsRebearth.Target.cs": (
            "class EchoheartsRebearthTarget",
            'ExtraModuleNames.Add("Echohearts")',
        ),
        "Source/EchoheartsRebearthEditor.Target.cs": (
            "class EchoheartsRebearthEditorTarget",
            'ExtraModuleNames.Add("Echohearts")',
        ),
    }
    for relative, tokens in targets.items():
        path = root / relative
        if not path.is_file():
            continue
        text = path.read_text(encoding="utf-8-sig", errors="replace")
        for token in tokens:
            if token not in text:
                errors.append(f"{relative} missing contract: {token}")

    print(json.dumps({
        "code": "ECO-INFRA-001",
        "name": "Echohearts: Rebearth",
        "status": "FAILED" if errors else "INFRASTRUCTURE_VALID",
        "errors": errors,
        "build": "NOT_RUN",
        "runtime": "NOT_VERIFIED",
        "recovery": "NOT_RUN"
    }, indent=2))
    return 1 if errors else 0

if __name__ == "__main__":
    raise SystemExit(main())
