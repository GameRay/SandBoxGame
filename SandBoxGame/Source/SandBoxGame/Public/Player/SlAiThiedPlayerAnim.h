// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Player/SlAiPlayerAnimInstance.h"
#include "SlAiThiedPlayerAnim.generated.h"

/**
 * 
 */
UCLASS()
class SANDBOXGAME_API USlAiThiedPlayerAnim : public USlAiPlayerAnimInstance
{
	GENERATED_BODY()
	USlAiThiedPlayerAnim();
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "PlayAnim")
	bool IsInAir;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "PlayAnim")
	float Direction;
};
