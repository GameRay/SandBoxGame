// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "SlAiPlayerCharacter.h"
#include "SlAiPlayerAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class SANDBOXGAME_API USlAiPlayerAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
public:
	USlAiPlayerAnimInstance();
protected:
	//获取角色指针
	void InitSPCharacter();

	 virtual void UpdateParameter();

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "PlayAnim")
	float Speed;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "PlayAnim")
	FRotator SpinRotator;
protected:
	ASlAiPlayerCharacter*SPCharacter;
	
};
