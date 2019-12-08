// Fill out your copyright notice in the Description page of Project Settings.


#include "SlAiGameHUD.h"
#include "Engine/Engine.h"
#include "Kismet/GameplayStatics.h"
#include "SSlAiGameHUDWidget.h"
ASlAiGameHUD::ASlAiGameHUD()
{
	if (GEngine&&GEngine->GameViewport)
	{
		SAssignNew(GameHUDWidget,SSlAiGameHUDWidget);
		GEngine->GameViewport->AddViewportWidgetContent(GameHUDWidget->AsShared());
	}
	

}
void ASlAiGameHUD::BeginPlay()
{
	Super::BeginPlay();
	GM = Cast<ASlAiGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	if (!GM)
	{
		return;
	}

	GM->InitGamePlayModule();
	GameHUDWidget->ShortcutWidget->RegisterShortCutContainer.BindUObject(GM->SPState,&ASlAiPlayerState::RegisterShortCutContainer);
												
}
