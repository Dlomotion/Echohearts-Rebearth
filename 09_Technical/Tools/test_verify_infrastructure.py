import json
import tempfile
import unittest
from pathlib import Path

from verify_infrastructure import validate_infrastructure


class VerifyInfrastructureTests(unittest.TestCase):
    def setUp(self):
        self.temp_dir = tempfile.TemporaryDirectory()
        self.root = Path(self.temp_dir.name)
        files = {
            ".gitignore": "",
            ".gitattributes": "",
            "EchoheartsRebearth.uproject": json.dumps({
                "EngineAssociation": "5.8",
                "Modules": [{"Name": "Echohearts", "Type": "Runtime"}],
            }),
            "package_unreal.ps1": "",
            "Source/EchoheartsRebearth.Target.cs": (
                "class EchoheartsRebearthTarget\n"
                'ExtraModuleNames.Add("Echohearts")'
            ),
            "Source/EchoheartsRebearthEditor.Target.cs": (
                "class EchoheartsRebearthEditorTarget\n"
                'ExtraModuleNames.Add("Echohearts")'
            ),
            "Source/Echohearts/Echohearts.Build.cs": (
                "class Echohearts : ModuleRules"
            ),
            "Source/Echohearts/Public/Echohearts.h": "",
            "Source/Echohearts/Private/EchoheartsModule.cpp": "",
        }
        for relative, contents in files.items():
            path = self.root / relative
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_text(contents, encoding="utf-8")

    def tearDown(self):
        self.temp_dir.cleanup()

    def test_accepts_canonical_echohearts_module(self):
        self.assertEqual([], validate_infrastructure(self.root))

    def test_rejects_superseded_runtime_module_files(self):
        legacy_files = (
            "Source/EchoheartsRebearth/EchoheartsRebearth.Build.cs",
            "Source/EchoheartsRebearth/EchoheartsRebearth.cpp",
        )
        for relative in legacy_files:
            with self.subTest(relative=relative):
                path = self.root / relative
                path.parent.mkdir(parents=True, exist_ok=True)
                path.write_text("", encoding="utf-8")
                errors = validate_infrastructure(self.root)
                self.assertIn(
                    f"Superseded runtime module file must not exist: {relative}",
                    errors,
                )
                path.unlink()

    def test_rejects_invalid_canonical_module_rules(self):
        (self.root / "Source/Echohearts/Echohearts.Build.cs").write_text(
            "class WrongName : ModuleRules",
            encoding="utf-8",
        )
        errors = validate_infrastructure(self.root)
        self.assertIn(
            "Source/Echohearts/Echohearts.Build.cs missing contract: "
            "class Echohearts : ModuleRules",
            errors,
        )

    def test_rejects_duplicate_runtime_module_declaration(self):
        project = self.root / "EchoheartsRebearth.uproject"
        project.write_text(json.dumps({
            "EngineAssociation": "5.8",
            "Modules": [
                {"Name": "Echohearts", "Type": "Runtime"},
                {"Name": "Echohearts", "Type": "Runtime"},
            ],
        }), encoding="utf-8")
        self.assertIn(
            "Project must declare runtime module Echohearts exactly once",
            validate_infrastructure(self.root),
        )


if __name__ == "__main__":
    unittest.main()
