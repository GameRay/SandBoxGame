// Fill out your copyright notice in the Description page of Project Settings.


#include "SlAiPlayerAnimInstance.h"

void USlAiPlayerAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{

	InitSPCharacter();
	UpdateParameter();
	UpdateMontage();

}

USlAiPlayerAnimInstance::USlAiPlayerAnimInstance()
{
	Speed = 0.f;
	SpinRotator = FRotator::ZeroRotator;
}

void USlAiPlayerAnimInstance::InitSPCharacter()
{
	if (!SPCharacter)
	{
		SPCharacter = Cast<ASlAiPlayerCharacter>(TryGetPawnOwner());
	}
}

void USlAiPlayerAnimInstance::UpdateParameter()
{
	if (!SPCharacter)return;
	Speed = SPCharacter->GetVelocity().Size();
}

void USlAiPlayerAnimInstance::UpdateMontage()
{
	if (!SPCharacter)
	{
		return;
	}
	/*if (!Montage_IsPlaying(PlayerPunchMontage))
	{
		Montage_Play(PlayerPunchMontage);
	}*/
	//如果当前动作没有停止，不更新动作
	if (!Montage_GetIsStopped(CurrentMontage))return;
	switch (SPCharacter->UpperType)
	{
	case EUpperBody::None:
		if (CurrentMontage!=nullptr)
		{
			Montage_Stop(0);
			CurrentMontage = nullptr;
		}
		break;
	case EUpperBody::Punch:
		if (!Montage_IsPlaying(PlayerPunchMontage))
		{
			Montage_Play(PlayerPunchMontage);
			CurrentMontage = PlayerPunchMontage;
		}
		break;
	case EUpperBody::Hit:
		if (!Montage_IsPlaying(PlayerHitMontage))
		{
			Montage_Play(PlayerHitMontage);
			CurrentMontage = PlayerHitMontage;
		}
		break;
	case EUpperBody::Fight:
		if (!Montage_IsPlaying(PlayerFightMontage))
		{
			Montage_Play(PlayerFightMontage);
			CurrentMontage = PlayerFightMontage;
		}
		break;
	case EUpperBody::PickUp:
		if (!Montage_IsPlaying(PlayerPickUpMontage))
		{
			Montage_Play(PlayerPickUpMontage);
			CurrentMontage = PlayerPickUpMontage;
		}
		break;
	case EUpperBody::Eat:
		if (!Montage_IsPlaying(PlayerEatMontage))
		{
			Montage_Play(PlayerEatMontage);
			CurrentMontage = PlayerEatMontage;
		}
		break;
	}
}
