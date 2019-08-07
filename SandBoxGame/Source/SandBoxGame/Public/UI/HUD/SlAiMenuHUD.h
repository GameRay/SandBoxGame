// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "SandBoxGame/Public/UI/Widget/SSlaiMenuHUDWidget.h"
#include "SlAiMenuHUD.generated.h"

/**
 * 
 */
UCLASS()
class SANDBOXGAME_API ASlAiMenuHUD : public AHUD
{
	GENERATED_BODY()
public:
	ASlAiMenuHUD();
	TSharedPtr<SSlaiMenuHUDWidget>MenuHUDWidget;
};
