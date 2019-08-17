// Fill out your copyright notice in the Description page of Project Settings.


#include "SlAiDaTaHandle.h"
#include"Internationalization.h"
TSharedPtr<SlAiDaTaHandle> SlAiDaTaHandle::DataInstance = NULL;
SlAiDaTaHandle::SlAiDaTaHandle()
{

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

void SlAiDaTaHandle::ChangeLocalizationCulture(ECultureTrem Culture)
{
	switch (Culture)
	{
	case ECultureTrem::EN:
		FInternationalization::Get().SetCurrentCulture("en");
		break;
	case ECultureTrem::ZH:
		FInternationalization::Get().SetCurrentCulture("zh");
		break;
	default:
		break;
	}
}

TSharedRef<SlAiDaTaHandle> SlAiDaTaHandle::Create()
{
	TSharedRef<SlAiDaTaHandle> DataRef = MakeShareable(new SlAiDaTaHandle());
	return DataRef;

}
