// Fill out your copyright notice in the Description page of Project Settings.


#include "SSlaiMenuHUDWidget.h"
#include "SlateOptMacros.h"
#include"SlAiStyle.h"
#include"SImage.h"
#include"SlAiMenuWidgetStyle.h"
#include"SlateWidgetStyleAsset.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SSlaiMenuHUDWidget::Construct(const FArguments& InArgs)
{

	MenuStyle = &SlAiStyle::Get().GetWidgetStyle<FSlAiMenuStyle>("BPSlAiMenuStyle");
	
	//UE_LOG(LogTemp,Warning,TEXT("jl %s"), *MenuStyle->MenuBackgroundBrush.GetResourceObject()->GetFName().ToString());
	//UE_LOG(LogTemp, Warning, TEXT("jl %s"), *StylEb.GetResourceObject()->GetFName().ToString());
	if (MenuStyle)


	{
		ChildSlot
			[
				SNew(SImage)
				//.Image(SlAiStyle::Get().GetBrush("JLBPS"))
				.Image(&MenuStyle->MenuBackgroundBrush)
			];
	}
	

}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
