// Fill out your copyright notice in the Description page of Project Settings.


#include "SlAiDaTaHandle.h"
#include"Internationalization.h"
#include "SlAiSingleton.h"
#include"SlAiJsonHandle.h"
#include "SlAiHelper.h"
#include "SlAiSingleton.h"
TSharedPtr<SlAiDaTaHandle> SlAiDaTaHandle::DataInstance = NULL;
SlAiDaTaHandle::SlAiDaTaHandle()
{
	InitRecordData();
	//CurrentCulture = ECultureTeam::ZH;
	//MusicVolume = 0.5f;
	//SoundVolume = 0.5f;
}

void SlAiDaTaHandle::Initialize()
{
	if (!DataInstance.IsValid())
	{
		DataInstance = Create();
	}
}

TSharedPtr<SlAiDaTaHandle> SlAiDaTaHandle::Get()
{
	Initialize();
	return DataInstance;
}

void SlAiDaTaHandle::ChangeLocalizationCulture(ECultureTeam Culture)
{
	switch (Culture)
	{
	case ECultureTeam::EN:
		FInternationalization::Get().SetCurrentCulture("en");
		break;
	case ECultureTeam::ZH:
		FInternationalization::Get().SetCurrentCulture("zh");
		break;
	default:
		break;
	}
	CurrentCulture = Culture;
	SlAiSingleton<SlAiJsonHandle>::Get()->UpdateRecordData(GetEnumValueAsString<ECultureTeam>("ECultureTeam", CurrentCulture)
		, MusicVolume, SoundVolume, &RecordDataList);
}

void SlAiDaTaHandle::ResetMenuVolume(float Music, float Sound)

{
	if (Music>=0)
	{
		MusicVolume = Music;
	}
	if (Sound)
	{
		SoundVolume = Sound;
	}
	SlAiSingleton<SlAiJsonHandle>::Get()->UpdateRecordData(GetEnumValueAsString<ECultureTeam>("ECultureTeam",CurrentCulture)
	,MusicVolume,SoundVolume,&RecordDataList);
}

float SlAiDaTaHandle::GetMusicVolume()
{
	return MusicVolume;
}

float SlAiDaTaHandle::GetSoundVolume()
{
	return SoundVolume;
}

void SlAiDaTaHandle::InitRecordData()
{
	RecordName = FString("");
	FString Culture;
	SlAiSingleton<SlAiJsonHandle>::Get()->RecordDataJsonRead(Culture,MusicVolume,SoundVolume,RecordDataList);

	//SlAiHelper::DEBUG(Culture + "--"+FString::SanitizeFloat(MusicVolume) + "--" + FString::SanitizeFloat(SoundVolume));
	//for (TArray<FString>::TIterator It(RecordDataList);It;++It )
	//{
	//SlAiHelper::DEBUG(*It);
	//}

	ChangeLocalizationCulture(GetEnumValueFromString<ECultureTeam>("ECultureTeam",Culture));
	ResetMenuVolume(MusicVolume, SoundVolume);
}

TSharedRef<SlAiDaTaHandle> SlAiDaTaHandle::Create()
{
	TSharedRef<SlAiDaTaHandle> DataRef = MakeShareable(new SlAiDaTaHandle());
	return DataRef;

}
