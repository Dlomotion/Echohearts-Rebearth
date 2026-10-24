"""Static proposal validator, not an Unreal actor/asset/spawn implementation."""
import json
import sys
from pathlib import Path

FILE = Path(__file__).resolve().parents[3] / "04_Systems" / "Data" / "skyisland_sanctuary_layouts.v1.json"

def validate(doc):
    assert doc["schema_version"] == 1
    assert doc["status"] == "PROPOSED_ONLY_NOT_RUNTIME"
    assert doc["public_attributes"] == ["Vibrance", "Density", "Harmony", "Purity"]
    assert len(doc["layouts"]) == 3
    ids = set()
    count = 0
    for layout in doc["layouts"]:
        ident = layout["layout_id"]
        assert ident not in ids
        ids.add(ident)
        w,h = layout["plot_size"]
        assert isinstance(w,int) and isinstance(h,int) and 0 < w <= 256 and 0 < h <= 256
        modules = layout["modules"]
        assert len(modules) > 0
        assert layout["entry_id"] in {m["module_type"] for m in modules}
        for i,a in enumerate(modules):
            assert all(type(a[key]) is int for key in ("x","y","width","height"))
            assert 0 <= a["x"] < w and 0 <= a["y"] < h
            assert a["width"] > 0 and a["height"] > 0
            assert a["x"] + a["width"] <= w
            assert a["y"] + a["height"] <= h
            for b in modules[:i]:
                intersects = (a["x"] < b["x"]+b["width"] and b["x"] < a["x"]+a["width"] and
                              a["y"] < b["y"]+b["height"] and b["y"] < a["y"]+a["height"])
                assert not intersects, f"{ident}: {a['module_type']} overlaps {b['module_type']}"
        count += len(modules)
    assert ids == {"SKY_STARTER", "SKY_REFINERY", "SKY_RECOVERY"}
    assert count == 35
    return count

if __name__ == "__main__":
    data = json.loads(FILE.read_text(encoding="utf-8"))
    print(f"Reference layout validation: {len(data['layouts'])} templates, {validate(data)} footprints; not UE verified")
