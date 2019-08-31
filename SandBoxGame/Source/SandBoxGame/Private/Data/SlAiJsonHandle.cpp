// Fill out your copyright notice in the Description page of Project Settings.


#include "SlAiJsonHandle.h"
#include "Paths.h"
#include "SlAiHelper.h"
#include "Json.h"
#include "JsonReader.h"
#include "SlAiSingleton.h"

SlAiJsonHandle::SlAiJsonHandle()
{
	RecordDataFileName = FString("RecordData.json");
	RelativePathJL = FString("Res/ConfigData/");
}

void SlAiJsonHandle::RecordDataJsonRead(FString & Culture, float & MusicVolume, float & SoundVolume, TArray<FString>& RecordDataList)
{
	FString JsonValue;
	if (!LoadStringFromFile(RecordDataFileName, RelativePathJL, JsonValue))
	{
		return;
	}
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

void SlAiJsonHandle::UpdateRecordData(FString Culture, float MusiVolume, float SoundVolume, TArray<FString>* RecordDataList)
{
	TSharedPtr <FJsonObject>JsonObject= MakeShareable(new FJsonObject);
	TArray<TSharedPtr<FJsonValue>>BaseDataArray;
	TSharedPtr<FJsonObject>CultureObject = MakeShareable(new FJsonObject);
	CultureObject->SetStringField("Culture", Culture);
	TSharedPtr<FJsonValueObject> CultureValue = MakeShareable(new FJsonValueObject(CultureObject));

	TSharedPtr<FJsonObject>MusicVolumeObject = MakeShareable(new FJsonObject);
	MusicVolumeObject->SetNumberField("MusicVolume", MusiVolume);
	TSharedPtr<FJsonValueObject> MusicVolumeValue = MakeShareable(new FJsonValueObject(MusicVolumeObject));

	TSharedPtr<FJsonObject>SoundVolumeObject = MakeShareable(new FJsonObject);
	SoundVolumeObject->SetNumberField("SoundVolume", SoundVolume);
	TSharedPtr<FJsonValueObject> SoundVolumeValue = MakeShareable(new FJsonValueObject(SoundVolumeObject));

	TArray<TSharedPtr<FJsonValue>> RecordDataArray;

	for (int i=0;i<RecordDataList->Num();i++)
	{
		TSharedPtr<FJsonObject> RecordItem = MakeShareable(new FJsonObject);
		RecordItem->SetStringField(FString::FromInt(i), ((*RecordDataList)[i]));
		TSharedPtr<FJsonValueObject>RecordDataValue = MakeShareable(new FJsonValueObject(RecordItem));
		RecordDataArray.Add(RecordDataValue);
	}
	TSharedPtr<FJsonObject>RecordDataObject = MakeShareable(new FJsonObject);
	RecordDataObject->SetArrayField("RecordData", RecordDataArray);
	TSharedPtr<FJsonValueObject>RecordDataValue = MakeShareable(new FJsonValueObject(RecordDataObject));


	BaseDataArray.Add(CultureValue);

	BaseDataArray.Add(MusicVolumeValue);

	BaseDataArray.Add(SoundVolumeValue);

	BaseDataArray.Add(RecordDataValue);

	JsonObject->SetArrayField("T", BaseDataArray);

	FString JsonStr;
	GetFStringInJsonData(JsonObject, JsonStr);

	SlAiHelper::DEBUG(FString("Origin Str:" + JsonStr));

	JsonStr.RemoveAt(0, 8);
	JsonStr.RemoveFromEnd(FString("}"));
	SlAiHelper::DEBUG(FString("Final Str:" + JsonStr));
	WriteFileWithJsonData(JsonStr, RelativePathJL,RecordDataFileName);
}

bool SlAiJsonHandle::LoadStringFromFile(const FString & FileName, const FString & RelaPath, FString & ResultString)
{
	if (!FileName.IsEmpty())
	{
		//FString AbsoPath = FPaths::ConvertRelativePathToFull(FPaths::ProjectContentDir() + RelativePathJL + RecordDataFileName) ;
		FString AbsoPath = FPaths::ProjectContentDir() + RelativePathJL + RecordDataFileName;
		//TCHAR*a = TEXT("/");
		//TCHAR*b = TEXT("\\");
		//AbsoPath = AbsoPath.Replace(a,b);
		//if (FPaths::DirectoryExists(AbsoPath))
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
		/*	else
			{
				SlAiHelper::DEBUG(FString("File Not Exist")+AbsoPath);
			}*/
	}
	return false;
}

bool SlAiJsonHandle::WriteFileWithJsonData(const FString & JsonStr, const FString & RelaPath, const FString & FileName)
{
	if (!JsonStr.IsEmpty())
	{
		FString path = FPaths::GameContentDir() + RelaPath + FileName;
		if (FFileHelper::SaveStringToFile(JsonStr,*path))
		{
			return true;
		}
		else
		{
			SlAiHelper::DEBUG(FString("Save") + path + FString("Failed"));
		}
	}
	return false;
}

bool SlAiJsonHandle::GetFStringInJsonData(const TSharedPtr<FJsonObject>&JsonObj, FString&JsonStr)
{
	if (JsonObj.IsValid()&&JsonObj->Values.Num()>0)
	{
		TSharedRef<TJsonWriter<TCHAR>>JsonWriter = TJsonWriterFactory<TCHAR>::Create(&JsonStr);
		FJsonSerializer::Serialize(JsonObj.ToSharedRef(), JsonWriter);
		return true;
	}
	return false;
}
