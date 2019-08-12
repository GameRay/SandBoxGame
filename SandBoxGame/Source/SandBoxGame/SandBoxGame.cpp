// Fill out your copyright notice in the Description page of Project Settings.

#include "SandBoxGame.h"
#include "Modules/ModuleManager.h"
#include "SlateStyleRegistry.h"
#include"SlAiStyle.h"

IMPLEMENT_PRIMARY_GAME_MODULE( FDefaultGameModuleImpl, SandBoxGame, "SandBoxGame" );

void SandBoxGameModule::StartupModule()
{
	FSlateStyleRegistry::UnRegisterSlateStyle(SlAiStyle::GetStyleSetName());
	SlAiStyle::Initialze();
}
void SandBoxGameModule::ShutdownModule()
{
	SlAiStyle::ShutDown();
}