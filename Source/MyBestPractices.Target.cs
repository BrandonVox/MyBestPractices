// Copyright Brandon Vox.

using UnrealBuildTool;
using System.Collections.Generic;

public class MyBestPracticesTarget : TargetRules
{
	public MyBestPracticesTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V7;

		ExtraModuleNames.AddRange( new string[] { "MyBestPractices" } );
	}
}
