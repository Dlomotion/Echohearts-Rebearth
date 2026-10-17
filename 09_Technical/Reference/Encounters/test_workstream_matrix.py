"""Static checks for the M01–M20 delivery ledger; these are NOT UE runtime tests."""
import json
from pathlib import Path
import unittest

ROOT = Path(__file__).resolve().parents[3]
MATRIX = ROOT / "10_Production" / "GAMEPLAY_GAP_DELIVERY_MATRIX_2026-10-17.json"

class GapDeliveryMatrixTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.data = json.loads(MATRIX.read_text(encoding="utf-8"))
        cls.rows = cls.data["workstreams"]
        cls.by_id = {row["id"]: row for row in cls.rows}

    def test_schema_and_scope(self):
        self.assertEqual(self.data["schema_version"], 1)
        self.assertEqual(self.data["authority"], "MASTER_PROJECT_INDEX.md")
        self.assertEqual(len(self.rows), 20)

    def test_workstream_ids_complete_unique(self):
        expected = {f"M{i:02d}" for i in range(1, 21)}
        self.assertEqual(set(self.by_id), expected)
        self.assertEqual(len(self.by_id), len(self.rows))

    def test_all_work_remains_gated(self):
        for row in self.rows:
            with self.subTest(row=row["id"]):
                self.assertEqual(row["status"], "DESIGNED_NOT_IMPLEMENTED")
                self.assertIs(row["engine_verified"], False)
                self.assertIs(row["source_audit_verified"], False)
                self.assertIs(row["existing_module_audit_required"], True)

    def test_no_duplicate_artifact_ids(self):
        names = [r["artifact_id"] for r in self.rows]
        self.assertEqual(len(names), len(set(names)))

    def test_no_unresolved_dependencies_or_cycles(self):
        visited = set()
        active = set()
        def visit(node):
            if node == "G00":
                return
            self.assertIn(node, self.by_id)
            self.assertNotIn(node, active, f"cyclic dependency: {node}")
            if node in visited:
                return
            active.add(node)
            for dependency in self.by_id[node]["depends_on"]:
                visit(dependency)
            active.remove(node)
            visited.add(node)
        for row in self.rows:
            visit(row["id"])
        self.assertEqual(len(visited), 20)

    def test_proof_not_confused_with_design(self):
        self.assertEqual(self.data["status_summary"]["ue_native"],
                         "BLOCKED_RUNTIME_REPO_UNAVAILABLE")
        self.assertEqual(self.data["status_summary"]["windows_compile"],
                         "NOT_VERIFIED")
        for row in self.rows:
            self.assertTrue(row["acceptance"])
            self.assertGreaterEqual(len(row["evidence_needed"]), 2)

    def test_offline_oracle_scope_limited(self):
        referenced = {r["id"] for r in self.rows if r["offline_reference_tests_existing"]}
        self.assertEqual(referenced, {"M02", "M05"})

    def test_source_authority_is_single_build_repo(self):
        self.assertEqual(
            {r["implementation_authority"] for r in self.rows},
            {"Dlomotion/ECHOHEARTS-REBEARTH-BUILD-"}
        )

if __name__ == "__main__":
    unittest.main()
