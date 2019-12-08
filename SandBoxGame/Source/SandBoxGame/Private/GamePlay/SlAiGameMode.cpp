// Fill out your copyright notice in the Description page of Project Settings.


#include "SlAiGameMode.h"
#include "SlAiPlayerController.h"
#include "SlAiPlayerCharacter.h"
#include "SlAiPlayerState.h"
#include "SlAiDaTaHandle.h"
#include "SlAiHelper.h"
#include "SlAIGameInstance.h"
#include "SlAiGameHUD.h"
#include "Kismet/GameplayStatics.h"
ASlAiGameMode::ASlAiGameMode()
{
	PrimaryActorTick.bCanEverTick = true;
	HUDClass = ASlAiGameHUD::StaticClass();
	PlayerControllerClass = ASlAiPlayerController::StaticClass();
	PlayerStateClass = ASlAiPlayerState::StaticClass();
	DefaultPawnClass = ASlAiPlayerCharacter::StaticClass();

}

void ASlAiGameMode::BeginPlay()
{
	SlAiDaTaHandle::Get()->InitializeGameData();
	if (!SPController)
	{
		InitGamePlayModule();
	}
}

void ASlAiGameMode::Tick(float DeltaSeconds)
{
}

void ASlAiGameMode::InitGamePlayModule()
{
	//
	SPController = Cast<ASlAiPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	SPCharacter = Cast<ASlAiPlayerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(),0));
	SPState = Cast<ASlAiPlayerState>(SPController->PlayerState);
}
