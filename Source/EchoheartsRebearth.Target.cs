using UnrealBuildTool;
public class EchoheartsRebearthTarget : TargetRules
{
    public EchoheartsRebearthTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Game;
        DefaultBuildSettings = BuildSettingsVersion.V5;
        ExtraModuleNames.Add("EchoheartsRebearth");
    }
}
