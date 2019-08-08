// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include"ISlateStyle.h"
#include"SlateStyle.h"
/**
 * 
 */
class SANDBOXGAME_API SlAiStyle
{
public:
	static void Initialze();
	static FName GetStyleSetName();
	static void ShutDown();
	static const ISlateStyle& Get();

private:
	static TSharedRef<FSlateStyleSet> Create();
	static TSharedPtr<FSlateStyleSet> SlAiStyleInstance;
};
