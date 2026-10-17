using UnrealBuildTool;

public class EchoheartsRebearth : ModuleRules
{
    public EchoheartsRebearth(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[]
        {
            "Core",
            "CoreUObject",
            "Engine",
            "InputCore",
            "EnhancedInput"
        });

        PrivateDependencyModuleNames.AddRange(new string[]
        {
            "AnimationCore",
            "AnimGraphRuntime",
            "GameplayTasks",
            "UMG"
        });
    }
}
