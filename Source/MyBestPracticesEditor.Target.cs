// Copyright Brandon Vox.

using UnrealBuildTool;
using System.Collections.Generic;

public class MyBestPracticesEditorTarget : TargetRules
{
	public MyBestPracticesEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V7;

		ExtraModuleNames.AddRange( new string[] { "MyBestPractices" } );
	}
}
