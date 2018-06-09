// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class UIExperienceTarget : TargetRules
{
	public UIExperienceTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
        bUseUnityBuild = false;

        ExtraModuleNames.AddRange( new string[] { "UIExperience" } );
	}
}
