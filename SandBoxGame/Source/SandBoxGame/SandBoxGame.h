// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

class SandBoxGameModule :public FDefaultModuleImpl
{
public:
	virtual void StartupModule()override;
	virtual void ShutdownModule()override;
};