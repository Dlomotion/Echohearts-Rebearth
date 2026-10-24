# Echo Cradle / Kindling separation QA — 2026-10-13

Status: **PROPOSAL CONTRACT CORRECTED / LOCAL POLICY ORACLE EXECUTED / NOT UE5.8 VERIFIED**

## Evidence and correction
Inspected PR #60 at `fc7944a70aea54e43b8344b5c2fd34080329142d`, the existing A.E.G.I.S. contract, hidden-wave JSON and art manifest. BUILD metadata and PR #51 returned 404 on 2026-10-13. The prior generic/native test claim cannot verify current BUILD policy.

The care outcome list still contained Kindle → Bond, despite the newer intake explicitly requiring independent domains. Removed that ambiguous outcome and specified that Cradle deployment, emergency care, treatment, refusal, timeout and release cannot grant or require a bond. Existing eligibility/consent/restriction authority remains mandatory. Pending hidden identities cannot enter production because a display name or pod exists.

## Local reference oracle — reproducible, not runtime code
The following complete original Python source expresses the contract for QA. It is retained here as a documentation oracle, not an alternative gameplay implementation. Eight explicitly expected scenarios are checked across five pod states and both emergency values: **80 eligibility decisions**, plus two checks that detect deliberately wrong pod-gate and emergency-grant mutations. These are **three unittest methods**, not 82 independent Unreal tests.

```python
"""Documentation-only policy oracle. Not an Unreal runtime implementation."""
import itertools
import unittest

def bond_allowed(approved, restricted, kindled, affirmative, pod, emergency):
    # Care transport and emergency aid never confer or require relationship authority.
    return approved and not restricted and kindled and affirmative

CASES = (
    (True, False, True, True, True),
    (True, False, True, False, False),
    (True, False, False, True, False),
    (True, True, True, True, False),
    (False, False, True, True, False),
    (False, True, False, False, False),
    (True, False, False, False, False),
    (True, True, True, False, False),
)
PODS = ("absent", "stowed", "deployed_open", "occupied_for_care", "recovered")

class ContractChecks(unittest.TestCase):
    def test_explicit_eligibility_and_transport_independence(self):
        for approved, restricted, kindled, affirmative, expected in CASES:
            for pod, emergency in itertools.product(PODS, (False, True)):
                with self.subTest(case=(approved, restricted, kindled, affirmative),
                                  pod=pod, emergency=emergency):
                    self.assertEqual(expected, bond_allowed(
                        approved, restricted, kindled, affirmative, pod, emergency))

    def test_detects_old_pod_gate_mutation(self):
        # A deliberately wrong requirement must disagree with an explicit allowed case.
        valid = bond_allowed(True, False, True, True, "absent", False)
        wrong = valid and "absent" == "deployed_open"
        self.assertTrue(valid)
        self.assertNotEqual(wrong, valid)

    def test_detects_emergency_grant_mutation(self):
        denied = bond_allowed(True, False, False, False, "occupied_for_care", True)
        wrong = denied or True
        self.assertFalse(denied)
        self.assertNotEqual(wrong, denied)

if __name__ == "__main__":
    unittest.main(verbosity=2)
```

### Retained run
- Python: 3.12.14 on this Linux environment
- Command: `python3 work/cradle_contract_oracle.py`
- Source SHA-256: `4916526c8afa19e03a7349208e48e13a6e1b86465fbb75bb028a139d063f9c63`
- Exit: 0
- Output:
```text
test_detects_emergency_grant_mutation ... ok
test_detects_old_pod_gate_mutation ... ok
test_explicit_eligibility_and_transport_independence ... ok
Ran 3 tests in 0.007s
OK
```

A snapshot-equality test that did not invoke any implementation was removed before the retained run because it could falsely imply care-event persistence was tested. No save, care-event dispatch, RPC, inventory, actor, roster or networking execution is proven by this oracle.

## Required actual BUILD tests — all NOT YET VERIFIED
| Case | Actual implementation assertion |
|---|---|
| Eligible ordinary Kindling, no Cradle equipped | Existing Kindling action succeeds under its ordinary rules |
| Eligible ordinary Kindling, Cradle in any lifecycle state | Identical relationship eligibility; care permissions remain independent |
| Refusal or incapacitation | No new affirmative Kindling; emergency care may operate under separate welfare authority |
| Restricted or unapproved identity | No production bind or access bypass; registry IDs resolved server-side |
| Care completion, release or timeout | Bond, roster membership and license count unchanged |
| Duplicate/out-of-order care request | One care result/charge; no relationship-event replay |
| Reconnect/save reload/actor destruction/travel | Existing bond preserved; no new bond; recover or release subject safely |
| Lost multicast/late join/relevancy change | Persistent authoritative care state reconstructs independently |
| Gamepad/mobile/accessibility modes | Refusal, defer, care and release remain distinguishable and operable |
| Concurrent Kindling and care | Serialized/version-checked authority; no cross-domain grant or lost update |

Use current BUILD types only after exact-head inspection. Prior `FEcoKinFieldContext`, `FEcoKinFieldSession`, `FEcoKinFieldRoster`, `SummonEcoKin` and `RecallEcoKin` names remain historical patch identifiers; definitions/API macros/ownership are unconfirmed.

Ordinary gameplay rejection belongs in server implementation. Epic's RPC documentation states that failed WithValidation disconnects the invoking client and that multicast reaches currently relevant clients; therefore it cannot replace persisted care state. Test finite positions, bounded payloads, authenticated actor resolution, sequence/version/idempotency, allocation limits, GC ownership, game-thread UObject mutation, save migration and authority bandwidth before promotion.

## Research/provenance checked 2026-10-13
- Epic UE5.8 RPC documentation: <https://dev.epicgames.com/documentation/en-us/unreal-engine/remote-procedure-calls-in-unreal-engine>. Official public reference, no sample code copied. Relevant to authority/validation/replication; target engine/toolchain still needs runtime evidence.
- Epic UE5.8 Automation Test Framework: <https://dev.epicgames.com/documentation/en-us/unreal-engine/automation-test-framework-in-unreal-engine>. Official public reference for unit/feature/functional testing and state isolation; no sample code copied.
- Epic documentation links CQTest under EpicGames/UnrealEngine. The linked source was inaccessible during this check; no license verified and no implementation borrowed.
- Python oracle is original project QA reference work. It uses the standard library only and creates no network listener, secrets, runner configuration or external dependency.

## Next exact engineering action
Restore BUILD access; inspect PR #51's actual policy files and native test inventory; apply this domain separation to the existing policy rather than inventing new classes; execute the above assertions through its native tests and then real Windows UE5.8 UHT/UBT/Automation. Record commit/toolchain/artifact/platform/test/log/result/reviewer/date for each claim.
