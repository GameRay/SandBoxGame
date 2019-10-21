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
	 virtual void UpdateMontage();

	 void AllowViewChange(bool allow);

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "PlayAnim")
	float Speed;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "PlayAnim")
	FRotator SpinRotator;
protected:
	ASlAiPlayerCharacter*SPCharacter;
	//上半身蒙太奇
	UAnimMontage*PlayerHitMontage;
	UAnimMontage*PlayerEatMontage;
	UAnimMontage*PlayerFightMontage;
	UAnimMontage*PlayerPunchMontage;
	UAnimMontage*PlayerPickUpMontage;
	//保存当前蒙太奇
	UAnimMontage*CurrentMontage;
	//指定自己的运行人称
	EGameViewMode::Type GameView;
	
};
