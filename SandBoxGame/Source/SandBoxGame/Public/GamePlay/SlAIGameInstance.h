// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "SlAIGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class SANDBOXGAME_API USlAIGameInstance : public UGameInstance
{
	GENERATED_BODY()
public:
	UPROPERTY(VisibleAnywhere, Category = "SlAi")
		FString GameName;
};
