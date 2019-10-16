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
	if (!Montage_IsPlaying(PlayerPunchMontage))
	{
		Montage_Play(PlayerPunchMontage);
	}
}
