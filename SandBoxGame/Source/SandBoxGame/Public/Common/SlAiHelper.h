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
}