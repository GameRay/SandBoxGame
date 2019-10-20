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
	
	//设置与动作
	LeftUpperType = EUpperBody::Punch;
	RightUpperType = EUpperBody::PickUp;
}

void ASlAiPlayerController::BeginPlay()
{
}

void ASlAiPlayerController::SetupInputComponent()
{

	Super::SetupInputComponent();
	InputComponent->BindAction("ChangeView",IE_Pressed,this,&ASlAiPlayerController::ChangeView);
	InputComponent->BindAction("LeftEvent", IE_Pressed, this, &ASlAiPlayerController::LeftEventStart);
	InputComponent->BindAction("LeftEvent", IE_Pressed, this, &ASlAiPlayerController::LeftEventStop);
	InputComponent->BindAction("RightEvent", IE_Pressed, this, &ASlAiPlayerController::RightEventStart);
	InputComponent->BindAction("RightEvent", IE_Pressed, this, &ASlAiPlayerController::RightEventStop);
}

void ASlAiPlayerController::ChangeView()
{
	switch (SPCharacter->GameView)
	{
	case EGameViewMode::First:
		SPCharacter->ChangeView(EGameViewMode::First);
		break;
	case EGameViewMode::Third:
		SPCharacter->ChangeView(EGameViewMode::Third);
		break;
	}
}

void ASlAiPlayerController::LeftEventStart()
{
}

void ASlAiPlayerController::LeftEventStop()
{
}

void ASlAiPlayerController::RightEventStart()
{
}

void ASlAiPlayerController::RightEventStop()
{
}
