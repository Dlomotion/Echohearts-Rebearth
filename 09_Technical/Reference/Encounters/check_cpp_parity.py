"""Differential checks against the existing oracle, never Unreal execution.

Usage: python3 check_cpp_parity.py /absolute/path/to/kindling-contract-tests
The supplied executable is trusted locally built test code, not user content.
"""
import itertools
from pathlib import Path
import subprocess
import sys

from encounter_contract import Ceremony, Evidence, MAX_REVISION, Rejected, transition


def main(executable):
    phases = ("encountered", "observed", "protected", "calm", "invited", "bond_ready",
              "refused", "released", "deferred", "invalid")
    actions = ("observe", "protect", "calm", "invite", "accept", "refuse", "release",
               "defer", "interrupt", "invalid")
    cases = list(itertools.product(phases, actions, (0,), (0,), range(128)))
    for revision, evidence_revision in ((MAX_REVISION-1, MAX_REVISION-1),
                                        (MAX_REVISION, MAX_REVISION),
                                        (-1, -1), (MAX_REVISION+1, MAX_REVISION+1),
                                        (0, 1), (1, 0)):
        cases.extend(itertools.product(phases, actions, (revision,),
                                       (evidence_revision,), (0, 111, 127)))
    lines, expected = [], []
    for phase, action, revision, evidence_revision, flags in cases:
        lines.append(f"{phase} {action} {revision} {evidence_revision} {flags}\n")
        evidence = Evidence("individual", evidence_revision,
                            *(bool(flags & (1 << bit)) for bit in range(7)))
        try:
            state = transition(Ceremony("encounter", "owner", "individual", phase, revision),
                               action, evidence)
            expected.append(f"ok {state.phase} {state.revision}")
        except Rejected as error:
            expected.append(f"error {error}")
    result = subprocess.run([str(Path(executable).resolve()), "--transitions"],
                            input="".join(lines), capture_output=True, text=True,
                            check=True, timeout=30)
    actual = result.stdout.splitlines()
    if len(actual) != len(expected):
        raise RuntimeError(f"result count: {len(actual)} != {len(expected)}")
    for case, want, got in zip(cases, expected, actual):
        if want != got:
            raise RuntimeError(f"parity mismatch {case}: Python={want!r}, C++={got!r}")
    print(f"{len(cases)} Python/C++ transition cases agree (offline reference only)")


if __name__ == "__main__":
    if len(sys.argv) != 2:
        raise SystemExit("usage: check_cpp_parity.py KINDLING_TEST_EXECUTABLE")
    main(sys.argv[1])
