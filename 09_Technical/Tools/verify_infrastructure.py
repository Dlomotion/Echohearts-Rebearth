#!/usr/bin/env python3
"""Read-only infrastructure validation. No Unreal/runtime verification."""
import argparse
import json
from pathlib import Path

def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument("step", choices=["infrastructure", "recovery-plan"])
    args = p.parse_args()
    if args.step == "recovery-plan":
        print(json.dumps({"status": "PLAN_ONLY", "profiles": [
            {"latency_ms": ms, "loss_fraction": loss, "result": "NOT_RUN"}
            for ms, loss in [(150, .01), (250, .03), (350, .05)]],
            "latency_definition": "UNRESOLVED: RTT or one-way",
            "acceptance_thresholds": "NOT_DEFINED", "ECO-API-001": "BLOCKED"}, indent=2))
        return 0
    root = Path(__file__).resolve().parents[2]
    required = [".gitignore", ".gitattributes", "EchoheartsRebearth.uproject",
                "package_unreal.ps1", "Source/EchoheartsRebearth.Target.cs",
                "Source/EchoheartsRebearthEditor.Target.cs",
                "Source/EchoheartsRebearth/EchoheartsRebearth.Build.cs",
                "Source/EchoheartsRebearth/EchoheartsRebearth.cpp"]
    errors = ["Missing: " + f for f in required if not (root / f).is_file()]
    descriptor = root / "EchoheartsRebearth.uproject"
    if descriptor.is_file():
        try:
            data = json.loads(descriptor.read_text())
            if data.get("EngineAssociation") != "5.8":
                errors.append("Project must declare engine 5.8")
        except (ValueError, AttributeError):
            errors.append("Invalid project JSON")
    print(json.dumps({"code": "ECO-INFRA-001", "name": "Echohearts: Rebearth",
                      "status": "FAILED" if errors else "INFRASTRUCTURE_VALID",
                      "errors": errors, "build": "NOT_RUN", "runtime": "NOT_VERIFIED",
                      "recovery": "NOT_RUN"}, indent=2))
    return 1 if errors else 0

if __name__ == "__main__":
    raise SystemExit(main())
