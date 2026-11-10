"""Run with Blender's bundled Python. Read-only art export preflight."""
import bpy
import json

def audit():
    problems = []
    meshes = [o for o in bpy.data.objects if o.type == "MESH"]
    rigs = [o for o in bpy.data.objects if o.type == "ARMATURE"]
    if not meshes:
        problems.append("No mesh found")
    if not rigs:
        problems.append("No skeleton/armature found")
    for obj in meshes:
        if any(abs(float(v) - 1) > 0.001 for v in obj.scale):
            problems.append(f"{obj.name}: scale not applied")
        if not obj.data.materials:
            problems.append(f"{obj.name}: missing material")
        if not any(mod.type == "ARMATURE" for mod in obj.modifiers):
            problems.append(f"{obj.name}: no armature modifier")
    return {"mesh_count": len(meshes), "rig_count": len(rigs), "issues": problems,
            "passed": not problems, "warning": "Does not prove canon approval, licensing or Unreal import."}

if __name__ == "__main__":
    print(json.dumps(audit(), indent=2))
