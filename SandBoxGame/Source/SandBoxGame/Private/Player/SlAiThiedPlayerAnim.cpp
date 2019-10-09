// Fill out your copyright notice in the Description page of Project Settings.


#include "SlAiThiedPlayerAnim.h"
#include "public/Player/SlAiPlayerCharacter.h"
#include "Classes/GameFramework/CharacterMovementComponent.h"

USlAiThiedPlayerAnim::USlAiThiedPlayerAnim()
{
	Direction = 0;
	IsInAir = false;
}

void USlAiThiedPlayerAnim::UpdateParameter()
{
	Super::UpdateParameter();
	if (SPCharacter) return;

	IsInAir = SPCharacter->GetCharacterMovement()->IsFalling();

	float PreDir = SPCharacter->GetVelocity().ToOrientationRotator().Yaw - SPCharacter->GetActorRotation().Yaw;

	if (PreDir>180.f)
	{
		PreDir -= 360.f;
	}


	if (PreDir <-180.f)
	{
		PreDir += 360.f;
	}

	Direction = PreDir;
}
