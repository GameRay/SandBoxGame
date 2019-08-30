// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include"Engine.h"

/**
 * 
 */

namespace SlAiHelper
{
	FORCEINLINE void DEBUG(FString Message,float Duration=3.f)
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, Duration,FColor::Yellow,Message);
		}
	}
	template<class UserClass>
	FORCEINLINE FTimerHandle PlayerSoundAndCall(UWorld*world,const FSlateSound sound, UserClass* InUserClass,typename FTimerDelegate::TRawMethodDelegate<UserClass>::FMethodPtr InMethod)
	{
		FSlateApplication::Get().PlaySound(sound);
		FTimerHandle Result;
		const float SoundDuration = FMath::Max(FSlateApplication::Get().GetSoundDuration(sound),0.1f);

		FTimerDelegate CallBack;
		CallBack.BindRaw(InUserClass, InMethod);
		world->GetTimerManager().SetTimer(Result,CallBack,SoundDuration,false);
		return Result;
	}
}