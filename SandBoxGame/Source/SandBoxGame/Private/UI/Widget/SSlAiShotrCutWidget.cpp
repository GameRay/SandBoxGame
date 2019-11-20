// Fill out your copyright notice in the Description page of Project Settings.


#include "SSlAiShotrCutWidget.h"
#include "SlateOptMacros.h"
#include"SlAiStyle.h"
#include"SlAiGameWidgetStyle.h"
#include"SBox.h"
#include"SOverlay.h"
#include"SBorder.h"
#include"Data/SlAiTypes.h"
#include"SlAiDaTaHandle.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SSlAiShotrCutWidget::Construct(const FArguments& InArgs)
{
	GameStyle = &SlAiStyle::Get().GetWidgetStyle<FSlAiGameStyle>(FName(TEXT("BPSlAiGameStyle")));
	
	ChildSlot
	[
		// Populate the widget
		SNew(SBox)
		.WidthOverride(900.f)
		.HeightOverride(160.f)
		[
			SNew(SOverlay)
			+SOverlay::Slot()
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Top)
			[
				SAssignNew(ShortcutInfoTextBlock,STextBlock)
				.Font(GameStyle->Font_Outline_40)
				.ColorAndOpacity(GameStyle->FontColor_White)
			]
			+ SOverlay::Slot()
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			.Padding(0.f,60.f,0.f,0.f)
			[
				SAssignNew(GridPanel,SUniformGridPanel)
			]
		]
	];
	IsInitializeContainer = false;
}
void SSlAiShotrCutWidget::Tick(const FGeometry & AllottedGeometry, const double InCurrentTime, const float InDeltaTime)
{
	if (!IsInitializeContainer)
	{
		InitializeContainer();
		IsInitializeContainer = true;
	}
}
void SSlAiShotrCutWidget::InitializeContainer()
{
	TArray<TSharedPtr<ShortcutContainer>>ContainerList;
	for (int i = 0; i < 9; i++)
	{
		TSharedPtr<SBorder> ContainerBorder;
		TSharedPtr<SBorder> ObjectImage;
		TSharedPtr<STextBlock> ObjectNumText;
		SAssignNew(ContainerBorder,SBorder)
			.Padding(FMargin(10.f))
			.BorderImage(&GameStyle->NormalContainerBrush)
			[
				SAssignNew(ObjectImage,SBorder)
				.HAlign(HAlign_Right)
				.VAlign(VAlign_Bottom)
				.Padding(FMargin(0.f,0.f,5.f,0.f))
				.BorderImage(&GameStyle->EmptyBrush)
				[
					SAssignNew(ObjectNumText,STextBlock)
					.Font(GameStyle->Font_Outline_20)
					.ColorAndOpacity(GameStyle->FontColor_Black)
					.Text(FText::FromString("12"))
				]
			];
		GridPanel->AddSlot(i, 0)
			[
				ContainerBorder->AsShared()
			];
			
		TSharedPtr<ShortcutContainer>Container = MakeShareable(new ShortcutContainer(ContainerBorder, ObjectImage, ObjectNumText, &GameStyle->NormalContainerBrush, &GameStyle->ChoosedContainerBrush,
			&SlAiDaTaHandle::Get()->ObjectBrushList));
		if (i==0)
		{
			Container->SetChoosed(true);
		}
		
		ContainerList.Add(Container);
	
	
	}
	RegisterShortCutContainer.ExecuteIfBound(&ContainerList, ShortcutInfoTextBlock);
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
