// Copyright EchoHearts Rebirth. MIT License — see LICENSE in the repo root folders.
using UnrealBuildTool;

public class EchoHeartsRebirth : ModuleRules
{
	public EchoHeartsRebirth(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "UMG", "Slate", "SlateCore"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });
	}
}
