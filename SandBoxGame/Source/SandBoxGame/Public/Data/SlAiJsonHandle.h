// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SlAiTypes.h"
#include "Json.h"

/**
 * 
 */
class SANDBOXGAME_API SlAiJsonHandle
{
public:
	SlAiJsonHandle();
	//Ω‚Œˆjson
void RecordDataJsonRead(FString&Culture, float&MusicVolume, float&SoundVolume, TArray<FString> &RecordDataList);
void UpdateRecordData(FString Culture,float MusiVolume,float SoundVolume,TArray<FString>*RecordDataList);

//Ω‚ŒˆObject
void ObjectAttrJsonRead(TMap<int, TSharedPtr<ObjectAttribute>>&ObjectAttrMap);

private:
bool LoadStringFromFile(const FString&FileName,const FString &RelaPath,FString&ResultString);
bool WriteFileWithJsonData(const FString&JsonStr,const FString&RelaPath,const FString&FileName);
bool GetFStringInJsonData(const TSharedPtr<FJsonObject>&JsonObj,FString&JsonStr);
EObjectType::Type StringToObjectType(const FString ArgStr);
private:
	FString RecordDataFileName;
	FString RelativePathJL;
	FString ObjectAttrFileName;
};
