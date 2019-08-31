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
	InitializedMenuAudio();
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

		for (TArray<USoundCue*>::TIterator It(*MenuAudioResource.Find(FString("Music"))); It; ++It)
		{
			(*It)->VolumeMultiplier = MusicVolume;
		}

		//for each (auto var in *MenuAudioResource.Find(FString("Music")))
		//{
		//	var->VolumeMultiplier = MusicVolume;
		//}

	/*	for (int i=0;i< MenuAudioResource.Find(FString("Music"))->Num();++i)
		{
			auto tarr=MenuAudioResource.Find(FString("Music"));
			(*tarr)[i]->VolumeMultiplier = MusicVolume;
		}*/
	}
	if (Sound>=0)
	{
		SoundVolume = Sound;

		for (TArray<USoundCue*>::TIterator It(*MenuAudioResource.Find(FString("Sound"))); It; ++It)
		{
			if (It)
			{
				(*It)->VolumeMultiplier = SoundVolume;
			}
			
		}


		/*for each (auto var in *MenuAudioResource.Find(FString("Sound")))
		{
			var->VolumeMultiplier = SoundVolume;
		}*/

		//for (int i=0; i < MenuAudioResource.Find(FString("Sound"))->Num(); ++i)
		//{
		//	auto tarr = MenuAudioResource.Find(FString("Sound"));
		//	(*tarr)[i]->VolumeMultiplier = Sound;
		//}
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
	//ResetMenuVolume(MusicVolume, SoundVolume);
}

TSharedRef<SlAiDaTaHandle> SlAiDaTaHandle::Create()
{
	TSharedRef<SlAiDaTaHandle> DataRef = MakeShareable(new SlAiDaTaHandle());
	return DataRef;

}

void SlAiDaTaHandle::InitializedMenuAudio()
{
	MenuStyle = &SlAiStyle::Get().GetWidgetStyle<FSlAiMenuStyle>("BPSlAiMenuStyle");
	TArray<USoundCue*> MusicList;
	MusicList.Add(Cast<USoundCue>(MenuStyle->MenuBackGroundMusic.GetResourceObject()));

	TArray<USoundCue*>SoundList;
	SoundList.Add(Cast<USoundCue>(MenuStyle->StartGameSound.GetResourceObject()));
	SoundList.Add(Cast<USoundCue>(MenuStyle->ExitGameSound.GetResourceObject()));
	SoundList.Add(Cast<USoundCue>(MenuStyle->MenuItemChangeGameSound.GetResourceObject()));
	MenuAudioResource.Add(FString("Music"), MusicList);
	MenuAudioResource.Add(FString("Sound"), SoundList);
	ResetMenuVolume(MusicVolume,SoundVolume);


}
