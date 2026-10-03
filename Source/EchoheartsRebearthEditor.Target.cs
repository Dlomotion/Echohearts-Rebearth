using UnrealBuildTool;
public class EchoheartsRebearthEditorTarget : TargetRules
{
    public EchoheartsRebearthEditorTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Editor;
        DefaultBuildSettings = BuildSettingsVersion.V5;
        ExtraModuleNames.Add("EchoheartsRebearth");
    }
}
