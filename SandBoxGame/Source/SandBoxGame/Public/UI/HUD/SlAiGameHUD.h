// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Widget/SSlAiGameHUDWidget.h"
#include "SlAiGameMode.h"
#include "SlAiGameHUD.generated.h"

/**
 * 
 */
UCLASS()
class SANDBOXGAME_API ASlAiGameHUD : public AHUD
{
	GENERATED_BODY()
	ASlAiGameHUD();
public:
	ASlAiGameMode*GM;
protected:
	virtual void BeginPlay() override;
private:
	TSharedPtr<SSlAiGameHUDWidget> GameHUDWidget;
	//TSharedRef<SSlAiGameHUDWidget>SlAiGameWidget;
};
