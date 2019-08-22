// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include"Public/Widgets/Input/SCheckBox.h"
#include"UI/Style/SlAiMenuWidgetStyle.h"
#include"SSlider.h"

/**
 * 
 */
class SANDBOXGAME_API SSlAiGameOptionWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SSlAiGameOptionWidget)
	{}
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);
private:
	void StyleInitialize();
	void ZhCheckBoxStateChanged(ECheckBoxState NewState);
	void EnCheckBoxStateChanged(ECheckBoxState NewState);
	void MusicSliderChanged(float Value);
	void SoundSliderChanged(float Value);
private:
	const struct FSlAiMenuStyle*MenuStyle;
	TSharedPtr<SCheckBox>ZhCheckBox;
	TSharedPtr<SCheckBox>EnCheckBox;
	TSharedPtr<SSlider>MuSlider;
	TSharedPtr<SSlider>SoSlider;
	TSharedPtr<STextBlock>MuTextBlock;
	TSharedPtr<STextBlock>SoTextBlock;
};
