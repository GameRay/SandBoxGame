// Fill out your copyright notice in the Description page of Project Settings.


#include "SlAiPlayerController.h"

ASlAiPlayerController::ASlAiPlayerController()
{
	PrimaryActorTick.bCanEverTick = true;
}
void ASlAiPlayerController::Tick(float DeltaSeconds)
{
	Super::BeginPlay();
	if (!SPCharacter)
	{
		SPCharacter = Cast<ASlAiPlayerCharacter>(GetCharacter());
	}
	bShowMouseCursor = false;
	FInputModeGameOnly InputMode;
	InputMode.SetConsumeCaptureMouseDown(true);
	SetInputMode(InputMode);
	
}

void ASlAiPlayerController::BeginPlay()
{
}

void ASlAiPlayerController::SetupInputComponent()
{

	Super::SetupInputComponent();
}
