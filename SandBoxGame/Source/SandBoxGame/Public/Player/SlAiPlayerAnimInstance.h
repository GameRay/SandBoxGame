// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "SlAiPlayerAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class SANDBOXGAME_API USlAiPlayerAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
public:
	USlAiPlayerAnimInstance();
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "PlayAnim")
	float Speed;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "PlayAnim")
	FRotator SpinRotator;
	
};
