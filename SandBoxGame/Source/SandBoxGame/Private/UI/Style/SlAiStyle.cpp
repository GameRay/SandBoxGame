// Fill out your copyright notice in the Description page of Project Settings.


#include "..\..\..\Public\UI\Style\SlAiStyle.h"
#include"SlateStyleRegistry.h"
#include"SlateGameResources.h"
TSharedPtr<FSlateStyleSet> SlAiStyle::SlAiStyleInstance = NULL;
void SlAiStyle::Initialze()
{
	if (!SlAiStyleInstance.IsValid())
	{
		SlAiStyleInstance = Create();
	}
	FSlateStyleRegistry::RegisterSlateStyle(*SlAiStyleInstance);
}

FName SlAiStyle::GetStyleSetName()
{
	return FName("SlAiStyle");
}

void SlAiStyle::ShutDown()
{
	FSlateStyleRegistry::UnRegisterSlateStyle(*SlAiStyleInstance);
	ensure(SlAiStyleInstance.IsUnique());
	SlAiStyleInstance.Reset();
}

const ISlateStyle & SlAiStyle::Get()
{
	// TODO: 在此处插入 return 语句
	return *SlAiStyleInstance;
}

TSharedRef<FSlateStyleSet> SlAiStyle::Create()
{
	//TSharedRef<FSlateStyleSet>StyleRef = MakeShareable(new FSlateStyleSet(GetStyleSetName()));
	TSharedRef <FSlateStyleSet>StyleRef = FSlateGameResources::New(GetStyleSetName(),"/Game/UI/HUD", "/Game/UI/HUD");
	StyleRef->Set("MenuItemFont",FSlateFontInfo("Roboto-Regular.ttf",50));
	return StyleRef;
}
