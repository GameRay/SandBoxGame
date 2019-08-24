// Fill out your copyright notice in the Description page of Project Settings.


#include "SlAiJsonHandle.h"
#include "Paths.h"
#include "SlAiHelper.h"
#include "Json.h"
#include "JsonReader.h"

SlAiJsonHandle::SlAiJsonHandle()
{
	RecordDataFileName = FString("RecordData.json");
	RelativePath = FString("Res/ConfigData/");
}

void SlAiJsonHandle::RecordDataJsonRead(FString & Culture, float & MusicVolume, float & SoundVolume, TArray<FString>& RecordDataList)
{
	FString JsonValue;
	LoadStringFromFile(RecordDataFileName, RelativePath, JsonValue);
	TArray<TSharedPtr<FJsonValue>>JsonParsed;
	TSharedRef<TJsonReader<TCHAR>>JsonReader = TJsonReaderFactory<TCHAR>::Create(JsonValue);

	if (FJsonSerializer::Deserialize(JsonReader,JsonParsed))
	{
		Culture = JsonParsed[0]->AsObject()->GetStringField("Culture");
		MusicVolume = JsonParsed[1]->AsObject()->GetNumberField("MusicVolume");
		SoundVolume = JsonParsed[2]->AsObject()->GetNumberField("SoundVolume");
		TArray<TSharedPtr<FJsonValue>>RecordDataArray = JsonParsed[3]->AsObject()->GetArrayField("RecordData");
		for (int i=0;i<RecordDataArray.Num();++i)
		{

			FString RecordDataName =RecordDataArray[i]->AsObject()->GetStringField(FString::FromInt(i));
			RecordDataList.Add(RecordDataName);

		}
	}
	else
	{
		SlAiHelper::DEBUG("Deserialize Failed");
	}
}

bool SlAiJsonHandle::LoadStringFromFile(const FString & FileName, const FString & RelaPath, FString & ResultString)
{
	if (!FileName.IsEmpty())
	{
		FString AbsoPath = FPaths::GameContentDir() + RelativePath + RecordDataFileName;
		if (FPaths::DirectoryExists(AbsoPath))
		{
			if (FFileHelper::LoadFileToString(ResultString,*AbsoPath))
			{
				return true;
			}
			else
			{
				SlAiHelper::DEBUG(FString("Load Error") + AbsoPath);
			}
		}
		else
		{
			SlAiHelper::DEBUG(FString("File Not Exist")+AbsoPath);
		}
	}
	return false;
}
