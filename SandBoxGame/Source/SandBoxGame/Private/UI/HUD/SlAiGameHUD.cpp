// Fill out your copyright notice in the Description page of Project Settings.


#include "SlAiGameHUD.h"
#include "SSlAiGameHUDWidget.h"
ASlAiGameHUD::ASlAiGameHUD()
{
	if (GEngine&&GEngine->GameViewport)
	{
		SAssignNew(SlAiGameWidget,SSlAiGameHUDWidget);
		GEngine->GameViewport->AddViewportWidgetContent(SlAiGameWidget->AsShared());
	}
	

}
void ASlAiGameHUD::BeginPlay()
{
	Super::BeginPlay();
}
