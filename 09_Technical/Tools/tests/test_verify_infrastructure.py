import json
import sys
import tempfile
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))

from verify_infrastructure import validate_infrastructure


class InfrastructureContractTests(unittest.TestCase):
    def setUp(self):
        self.temp_dir = tempfile.TemporaryDirectory()
        self.root = Path(self.temp_dir.name)
        for relative in (
            ".gitignore",
            ".gitattributes",
            "package_unreal.ps1",
            "Source/EchoheartsRebearth.Target.cs",
            "Source/EchoheartsRebearthEditor.Target.cs",
            "Source/Echohearts/Echohearts.Build.cs",
            "Source/Echohearts/Public/Echohearts.h",
            "Source/Echohearts/Private/EchoheartsModule.cpp",
        ):
            path = self.root / relative
            path.parent.mkdir(parents=True, exist_ok=True)
            path.touch()

        (self.root / "EchoheartsRebearth.uproject").write_text(
            json.dumps({
                "EngineAssociation": "5.8",
                "Modules": [{"Name": "Echohearts", "Type": "Runtime"}],
            }),
            encoding="utf-8",
        )
        for relative in (
            "Source/EchoheartsRebearth.Target.cs",
            "Source/EchoheartsRebearthEditor.Target.cs",
        ):
            target_class = Path(relative).name.removesuffix(".Target.cs") + "Target"
            (self.root / relative).write_text(
                f"class {target_class} {{ ExtraModuleNames.Add(\"Echohearts\") }}",
                encoding="utf-8",
            )

    def tearDown(self):
        self.temp_dir.cleanup()

    def test_accepts_the_single_canonical_echohearts_module(self):
        self.assertEqual(validate_infrastructure(self.root), [])
        self.assertFalse((self.root / "Source/EchoheartsRebearth").exists())

    def test_requires_the_canonical_module_implementation(self):
        (self.root / "Source/Echohearts/Private/EchoheartsModule.cpp").unlink()

        self.assertIn(
            "Missing: Source/Echohearts/Private/EchoheartsModule.cpp",
            validate_infrastructure(self.root),
        )


if __name__ == "__main__":
    unittest.main()
