// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include"SlAiTypes.h"

/**
 * 
 */
class SANDBOXGAME_API SlAiDaTaHandle
{
public:
	SlAiDaTaHandle();
	static void Initialize();
	static TSharedPtr<SlAiDaTaHandle> Get();

	void ChangeLocalizationCulture(ECultureTeam Culture);
public:
	ECultureTeam CurrentCulture;
	void ResetMenuVolume(float Music, float Sound);
	float GetMusicVolume();
	float GetSoundVolume();

private:
	static TSharedRef<SlAiDaTaHandle> Create();
	float MusicVolume;
	float SoundVolume;

private:
	static TSharedPtr<SlAiDaTaHandle> DataInstance;
};
