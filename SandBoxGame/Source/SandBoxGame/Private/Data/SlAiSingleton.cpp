// Fill out your copyright notice in the Description page of Project Settings.


#include "SlAiSingleton.h"
template<class T>
TSharedPtr<T> SlAiSingleton<T>::TInstance = NULL;
template<class T>
TSharedRef<T> SlAiSingleton<T>::Create()
{
	TSharedPtr<T> TRef = MakeShareable(new T());
	return TRef;
}
template<class T>
void SlAiSingleton<T>::Initialize()
{
	if (!TInstance->IsValid())
	{
		TInstance = create();
	}
}
template<class T>
TSharedPtr<T>SlAiSingleton<T>::Get()
{
	Initialize();
	return TInstance;
}
