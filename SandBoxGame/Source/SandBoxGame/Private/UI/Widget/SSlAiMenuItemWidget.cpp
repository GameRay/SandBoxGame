// Fill out your copyright notice in the Description page of Project Settings.


#include "SSlAiMenuItemWidget.h"
#include "SlateOptMacros.h"
#include"SlAiStyle.h"
#include"SBox.h"
#include"SOverlay.h"
#include"SImage.h"
#include"STextBlock.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SSlAiMenuItemWidget::Construct(const FArguments& InArgs)
{
	MenuStyle = &SlAiStyle::Get().GetWidgetStyle<FSlAiMenuStyle>("BPSlAiMenuStyle");
	OnClicked = InArgs._OnClicked;
	ItemType = InArgs._ItemType.Get();
	
	
	ChildSlot
	[
		// Populate the widget
		SNew(SBox)
		.WidthOverride(500.f)
		.HeightOverride(100.f)
		[
			SNew(SOverlay)
			+SOverlay::Slot()
			.VAlign(VAlign_Fill)
			.HAlign(HAlign_Fill)
			[
				SNew(SImage)
				.Image(&MenuStyle->MenuItemBrush)
				.ColorAndOpacity(this,& SSlAiMenuItemWidget::GetTinColor)
			]
			+SOverlay::Slot()
			 .VAlign(VAlign_Center)
			 .HAlign(HAlign_Center)
			[
				SNew(STextBlock)
				.Text(InArgs._ItemText)
				.Font(MenuStyle->Font_60)
			]
		]


	];
	IsMouseButtonDown = false;
	
}
FReply SSlAiMenuItemWidget::OnMouseButtonDown(const FGeometry&MyGeometry,const FPointerEvent&MouseEvent)
{
	IsMouseButtonDown = true;
	return FReply::Handled();

}
FReply SSlAiMenuItemWidget::OnMouseButtonUp(const FGeometry&MyGeometry,const FPointerEvent&MouseEvent)
{

	if (IsMouseButtonDown)
	{
		IsMouseButtonDown = false;
		OnClicked.ExecuteIfBound(ItemType);
	}
	return FReply::Handled();
}
void SSlAiMenuItemWidget::OnMouseLeave(const FPointerEvent&MouseEvent)
{
	IsMouseButtonDown = false;
}
FSlateColor SSlAiMenuItemWidget::GetTinColor()const
{
	if (IsMouseButtonDown)
	{
		return FLinearColor(1.f, 1.f, 1.f, 0.5f);
	}
	return FLinearColor(1.f, 1.f, 1.f, 1.0f);
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
