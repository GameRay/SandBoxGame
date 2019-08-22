// Fill out your copyright notice in the Description page of Project Settings.


#include "SlAiDaTaHandle.h"
#include"Internationalization.h"
TSharedPtr<SlAiDaTaHandle> SlAiDaTaHandle::DataInstance = NULL;
SlAiDaTaHandle::SlAiDaTaHandle()
{
	CurrentCulture = ECultureTeam::ZH;
	MusicVolume = 0.5f;
	SoundVolume = 0.5f;
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
}

float SlAiDaTaHandle::GetMusicVolume()
{
	return MusicVolume;
}

float SlAiDaTaHandle::GetSoundVolume()
{
	return SoundVolume;
}

TSharedRef<SlAiDaTaHandle> SlAiDaTaHandle::Create()
{
	TSharedRef<SlAiDaTaHandle> DataRef = MakeShareable(new SlAiDaTaHandle());
	return DataRef;

}
