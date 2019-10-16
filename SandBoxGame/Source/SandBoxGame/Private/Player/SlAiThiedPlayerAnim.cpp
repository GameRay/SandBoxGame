// Fill out your copyright notice in the Description page of Project Settings.


#include "SlAiThiedPlayerAnim.h"
#include "public/Player/SlAiPlayerCharacter.h"
#include "Classes/GameFramework/CharacterMovementComponent.h"
#include "ConstructorHelpers.h"

USlAiThiedPlayerAnim::USlAiThiedPlayerAnim()
{
	Direction = 0;
	IsInAir = false;
	//绑定蒙太奇及资源
	static ConstructorHelpers::FObjectFinder<UAnimMontage>PlayerHitMon(TEXT("AnimMontage'/Game/Res/PolygonAdventure/Mannequin/Player/Animation/UpperBody/PlayerHitMontage.PlayerHitMontage'"));
	PlayerHitMontage = PlayerHitMon.Object;
	static ConstructorHelpers::FObjectFinder<UAnimMontage>PlayerEatMon(TEXT("AnimMontage'/Game/Res/PolygonAdventure/Mannequin/Player/Animation/UpperBody/PlayerEatMontage.PlayerEatMontage'"));
	PlayerEatMontage = PlayerEatMon.Object;
	static ConstructorHelpers::FObjectFinder<UAnimMontage>PlayerFightMon(TEXT("AnimMontage'/Game/Res/PolygonAdventure/Mannequin/Player/Animation/UpperBody/PlayerFightMontage.PlayerFightMontage'"));
	PlayerFightMontage = PlayerFightMon.Object;
	static ConstructorHelpers::FObjectFinder<UAnimMontage>PlayerPunchMon(TEXT("AnimMontage'/Game/Res/PolygonAdventure/Mannequin/Player/Animation/UpperBody/PlayerPunchMontage.PlayerPunchMontage'"));
	PlayerPunchMontage = PlayerPunchMon.Object;
	static ConstructorHelpers::FObjectFinder<UAnimMontage>PlayerPickUpMon(TEXT("AnimMontage'/Game/Res/PolygonAdventure/Mannequin/Player/Animation/UpperBody/PlayerPunchMontage.PlayerPunchMontage'"));
	PlayerPickUpMontage = PlayerPickUpMon.Object;

}

void USlAiThiedPlayerAnim::UpdateParameter()
{
	Super::UpdateParameter();
	if (!SPCharacter) return;

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
