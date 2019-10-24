// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include "UI/Widget/SSlAiShotrCutWidget.h"
#include "Slate/Public/Widgets/Layout/SDPIScaler.h"
#include "SlateCore/Public/Widgets/SOverlay.h"

/**
 * 
 */
class SANDBOXGAME_API SSlAiGameHUDWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SSlAiGameHUDWidget)
	{}
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);
	float GetUIScaler()const;
public:
	TSharedPtr<SSlAiShotrCutWidget> ShortcutWidget;
private:
	FVector2D GetViewPortSize()const;
private:
	TAttribute<float>UIScaler;
};
