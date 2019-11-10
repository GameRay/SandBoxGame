// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include"SlAiTypes.h"
#include "Engine/Classes/Sound/SoundCue.h"
#include "SlAiStyle.h"
#include "SlAiMenuWidgetStyle.h"

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
	void InitializeGameData();
public:
	ECultureTeam CurrentCulture;
	void ResetMenuVolume(float Music, float Sound);
	float GetMusicVolume();
	float GetSoundVolume();
	TArray<FString>RecordDataList;
	FString RecordName;
	//物品属性图
	TMap<int, TSharedPtr<ObjectAttribute>> ObjectAttrMap;

private:
	void InitRecordData();
	static TSharedRef<SlAiDaTaHandle> Create();
	template<typename TEnum>
	FString GetEnumValueAsString(const FString&Name, TEnum Value);
	template<typename TEnum>
	TEnum GetEnumValueFromString(const FString&Name, FString Value);
	void InitializedMenuAudio();
	//初始化物品属性
	void InitObjectAttr();

public:
	TArray<const FSlateBrush*>ObjectBrushList;
private:
	static TSharedPtr<SlAiDaTaHandle> DataInstance;
	float MusicVolume;
	float SoundVolume;
	TMap<FString, TArray<USoundCue*>> MenuAudioResource;
	const struct FSlAiMenuStyle*MenuStyle;
	const struct FSlAiGameStyle*GameStyle;

};

template<typename TEnum>
inline FString SlAiDaTaHandle::GetEnumValueAsString(const FString & Name, TEnum Value)
{
	const UEnum*EnumPtr = FindObject<UEnum>(ANY_PACKAGE, *Name, true);
	if (!EnumPtr)
	{
		return FString("InValid");
	}
	return EnumPtr->GetNameStringByIndex((int32)Value);
}

template<typename TEnum>
inline TEnum SlAiDaTaHandle::GetEnumValueFromString(const FString & Name, FString Value)
{
	const UEnum*EnumPtr = FindObject<UEnum>(ANY_PACKAGE, *Name, true);
	if (!EnumPtr)
	{
		return TEnum(0);
	}
	return  (TEnum)EnumPtr->GetIndexByName(FName(*Value));
}
