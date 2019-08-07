// Fill out your copyright notice in the Description page of Project Settings.


#include"SandBoxGame/Public/UI/HUD/SlAiMenuHUD.h"
#include "Engine.h"
ASlAiMenuHUD::ASlAiMenuHUD()
{
	if (GEngine&&GEngine->GameViewport)
	{
		SAssignNew(MenuHUDWidget,SSlaiMenuHUDWidget);
		GEngine->GameViewport->AddViewportWidgetContent(MenuHUDWidget->AsShared());
	}
}
