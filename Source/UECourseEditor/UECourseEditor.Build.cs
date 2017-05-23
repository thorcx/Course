// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class UECourseEditor : ModuleRules
{
	public UECourseEditor(TargetInfo Target)
	{
		PublicDependencyModuleNames.AddRange(new string[] {
            "Core",
            "CoreUObject",
            "Engine",
            "InputCore",
            "ShaderCore", 
            "RHI",
            "RenderCore",
            "Kismet",
            "Slate",
            "SlateCore",
			"UECourse",
            "MainFrame",
            "EditorStyle",
            //蓝图自定义节点需要以下模块
            "AppFramework",
            "GraphEditor",
            "PropertyEditor"
        });

		PrivateDependencyModuleNames.AddRange(new string[] {
			
			"UnrealEd"
            
        });

        PrivateIncludePaths.AddRange(
            new string[] {
                "Editor/PropertyEditor/Public"


        });

        // Uncomment if you are using Slate UI
        // PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

            // Uncomment if you are using online features
            // PrivateDependencyModuleNames.Add("OnlineSubsystem");

            // To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
    }
}
