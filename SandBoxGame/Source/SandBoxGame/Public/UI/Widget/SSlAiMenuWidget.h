// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include"SBox.h"
#include"SlAiMenuWidgetStyle.h"
#include"STextBlock.h"
#include"VerticalBox.h"
#include"SSlAiMenuItemWidget.h"
#include"SlAiDaTaHandle.h"
#include"SlAiTypes.h"
/*
 * 
 */

class SANDBOXGAME_API SSlAiMenuWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SSlAiMenuWidget)
	{}
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);
private:
	void MenuItemOnClicked(EMenuItem::Type);
	void ChangeCulture(ECultureTeam culture);
	void ChangeVolume(float Music, float Sound);
private:
	const struct FSlAiMenuStyle*MenuStyle;
	TSharedPtr<SBox>RootSizeBox;
	TSharedPtr<STextBlock>TitleText;
	TSharedPtr<SVerticalBox>ContentBox;

};
