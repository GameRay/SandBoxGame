// Fill out your copyright notice in the Description page of Project Settings.


#include"SlAiMenuGameMode.h"
#include"SlAiMenuController.h"
#include"UI/HUD/SlAiMenuHUD.h"
#include "SlAIGameInstance.h"
#include "Kismet/GameplayStatics.h"
ASlAiMenuGameMode::ASlAiMenuGameMode()
{
	PlayerControllerClass = ASlAiMenuController::StaticClass();
	HUDClass = ASlAiMenuHUD::StaticClass();
}

void ASlAiMenuGameMode::BeginPlay()
{
	Cast<USlAIGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()))->GameName = FString("SlAiCourse");
}
