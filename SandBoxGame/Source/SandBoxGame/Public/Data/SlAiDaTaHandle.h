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
	ECultureTrem CurrentCulture;
	void ChangeLocalizationCulture(ECultureTrem Culture);
private:
	static TSharedRef<SlAiDaTaHandle> Create();
private:
	static TSharedPtr<SlAiDaTaHandle> DataInstance;
};
