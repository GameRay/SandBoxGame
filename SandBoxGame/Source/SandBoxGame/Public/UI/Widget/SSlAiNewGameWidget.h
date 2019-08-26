// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include"SEditableTextBox.h"
#include"SlAiMenuWidgetStyle.h"

/**
 * 
 */
class SANDBOXGAME_API SSlAiNewGameWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SSlAiNewGameWidget)
	{}
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);
	bool AllowEnterGame();
private:
	const struct FSlAiMenuStyle*MenuStyle;
	TSharedPtr<SEditableTextBox>EditTextBox;
};
