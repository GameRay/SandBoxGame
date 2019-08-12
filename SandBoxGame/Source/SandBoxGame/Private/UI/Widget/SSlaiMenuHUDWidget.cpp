// Fill out your copyright notice in the Description page of Project Settings.


#include "SSlaiMenuHUDWidget.h"
#include "SlateOptMacros.h"
#include"SlAiStyle.h"
#include"SImage.h"
#include"SlAiMenuWidgetStyle.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SSlaiMenuHUDWidget::Construct(const FArguments& InArgs)
{
	MenuStyle = &SlAiStyle::Get().GetWidgetStyle<FSlAiMenuStyle>("BPSlAiMenuStyle");
	if (MenuStyle)
	{
		ChildSlot
			[
				SNew(SImage)
				.Image(&MenuStyle->MenuBackgroundBrush)
			];
	}
	

}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
