using UnrealBuildTool;
using System.Collections.Generic;

public class EchoheartsRebearthEditorTarget : TargetRules
{
    public EchoheartsRebearthEditorTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Editor;
        DefaultBuildSettings = BuildSettingsVersion.V6;
        IncludeOrderVersion = EngineIncludeOrderVersion.Latest;
        ExtraModuleNames.Add("Echohearts");
    }
}
