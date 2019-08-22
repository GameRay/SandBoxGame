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
	template<typename TEnum>
	FString GetEnumValueAsString(const FString&Name, TEnum Value);
	template<typename TEnum>
	TEnum GetEnumValueFromString(const FString&Name, FString Value);
	


private:
	static TSharedPtr<SlAiDaTaHandle> DataInstance;
	float MusicVolume;
	float SoundVolume;
};

template<typename TEnum>
inline FString SlAiDaTaHandle::GetEnumValueAsString(const FString & Name, TEnum Value)
{
	const UEnum*EnumPtr = FindObject<UEnum>(ANY_PACKAGE, *Name, true);
	if (!EnumPtr)
	{
		return FString("InValid");
	}
	return EnumPtr->GetEnumName((int32)Value);
}

template<typename TEnum>
inline TEnum SlAiDaTaHandle::GetEnumValueFromString(const FString & Name, FString Value)
{
	const UEnum*EnumPtr = FindObject<UEnum>(ANY_PACKAGE, *Name, true);
	if (!EnumPtr)
	{
		return TEnum(0);
	}
	return EnumPtr->GetIndexByName(FName(*Value));
}
