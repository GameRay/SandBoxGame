// Fill out your copyright notice in the Description page of Project Settings.


#include"SlAiMenuGameMode.h"
#include"SlAiMenuController.h"
#include"UI/HUD/SlAiMenuHUD.h"

ASlAiMenuGameMode::ASlAiMenuGameMode()
{
	PlayerControllerClass = ASlAiMenuController::StaticClass();
	HUDClass = ASlAiMenuHUD::StaticClass();
}

