// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class SANDBOXGAME_API SlAiJsonHandle
{
public:
	SlAiJsonHandle();
private:
bool LoadStringFromFile(const FString&FileName,const FString &RelaPath,FString&ResultString);
private:
	FString RecordDataFileName;
	FString RelativePath;
};
