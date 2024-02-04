// Copyright Epic Games, Inc. All Rights Reserved.

#include "WavesGenerator.h"
#include "Interfaces/IPluginManager.h"


#define LOCTEXT_NAMESPACE "FWavesGeneratorModule"

void FWavesGeneratorModule::StartupModule()
{
	const IPlugin& Plugin = *IPluginManager::Get().FindPlugin("WavesGenerator");
	const FString ShaderDirectory = FPaths::ConvertRelativePathToFull(Plugin.GetBaseDir() / "Shaders/Private");
	AddShaderSourceDirectoryMapping("/Shaders", ShaderDirectory);
}

void FWavesGeneratorModule::ShutdownModule()
{
	ResetAllShaderSourceDirectoryMappings();
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FWavesGeneratorModule, WavesGenerator)