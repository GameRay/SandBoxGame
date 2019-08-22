// Fill out your copyright notice in the Description page of Project Settings.


#include "SlAiJsonHandle.h"
#include "Paths.h"
#include "SlAiHelper.h"

SlAiJsonHandle::SlAiJsonHandle()
{
	RecordDataFileName = FString("RecordData.json");
	RelativePath = FString("Res/ConfigData/");
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
