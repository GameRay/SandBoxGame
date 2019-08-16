// Fill out your copyright notice in the Description page of Project Settings.


#include "SSlAiMenuWidget.h"
#include "SlateOptMacros.h"
#include"SlAiStyle.h"
#include"Public/Widgets/DeclarativeSyntaxSupport.h"
#include"SOverlay.h"
#include"SImage.h"
#include"SBorder.h"
#include"Internationalization.h"

#define LOCTEXT_NAMESPACE "SSlAiMenuWidget"
BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SSlAiMenuWidget::Construct(const FArguments& InArgs)
{
	MenuStyle = &SlAiStyle::Get().GetWidgetStyle<FSlAiMenuStyle>("BPSlAiMenuStyle");
	
	FInternationalization::Get().SetCurrentCulture(TEXT("en"));
	ChildSlot
	[
		SAssignNew(RootSizeBox,SBox).HAlign(HAlign_Center).VAlign(VAlign_Center)
		.WidthOverride(600.f)
		.HeightOverride(510.f)
		[
			SNew(SOverlay)
			+SOverlay::Slot()
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			.Padding(0.f, 50.f, 0.f, 0.f)
			[
				SNew(SImage)
				.Image(&MenuStyle->MenuBackgroundBrush)
			]
			+ SOverlay::Slot()
			.HAlign(HAlign_Left)
			.VAlign(VAlign_Center)
			.Padding(0.f, 25.f, 0.f, 0.f)
			[
				SNew(SImage)
				.Image(&MenuStyle->LeftIconBrush)
			]
			+ SOverlay::Slot()
				.HAlign(HAlign_Right)
				.VAlign(VAlign_Center)
				.Padding(0.f, 25.f, 0.f, 0.f)
				[
					SNew(SImage)
					.Image(&MenuStyle->RightIconBrush)
				]
			+ SOverlay::Slot()
				.HAlign(HAlign_Right)
				.VAlign(VAlign_Center)
				.Padding(0.f, 25.f, 0.f, 0.f)
				[
					SNew(SImage)
					.Image(&MenuStyle->RightIconBrush)
				]
			+SOverlay::Slot()
				.HAlign(HAlign_Center)
				.VAlign(VAlign_Top)
				[
					SNew(SBox)
					.WidthOverride(400.f)
					.HeightOverride(100.f)
					[
						SNew(SBorder)
						.BorderImage(&MenuStyle->TitleBorderBrush)
						.HAlign(HAlign_Center)
						.VAlign(VAlign_Center)
						[
							SAssignNew(TitleText,STextBlock)
							.Font(SlAiStyle::Get().GetFontStyle("MenuItemFont"))
							.Text(NSLOCTEXT("SlAiMenu", "Menu", "Menu"))
							//.Text(FText::FromString(TEXT("题目")))
						]

						
					]
				]
		]
	];
	
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
#undef LOCTEXT_NAMESPACE
