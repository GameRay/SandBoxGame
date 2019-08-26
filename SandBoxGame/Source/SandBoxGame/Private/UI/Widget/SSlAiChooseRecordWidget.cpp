// Fill out your copyright notice in the Description page of Project Settings.


#include "SSlAiChooseRecordWidget.h"
#include "SlateOptMacros.h"
#include"SlAiStyle.h"
#include "SlAiStyle.h"
#include"SBox.h"
#include"SOverlay.h"
#include"SImage.h"
#include"STextBlock.h"
#include"SlAiMenuWidgetStyle.h"
#include"SlAiDaTaHandle.h"
BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SSlAiChooseRecordWidget::Construct(const FArguments& InArgs)
{
	MenuStyle = &SlAiStyle::Get().GetWidgetStyle<FSlAiMenuStyle>("BPSlAiMenuStyle");
	OptionsSource.Empty();
	for (TArray<FString>::TIterator It(SlAiDaTaHandle::Get()->RecordDataList); It; ++It)
	{
		OptionsSource.Add(MakeShareable(new FString(*It)));
		
	}

	ChildSlot
		[
			// Populate the widget
			SNew(SBox)
			.WidthOverride(500.f)
		.HeightOverride(100.f)
		[
			SNew(SOverlay)
			+ SOverlay::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		[
			SNew(SImage)
			.Image(&MenuStyle->MenuItemBrush)
		]
	+ SOverlay::Slot()
		.HAlign(HAlign_Left)
		.VAlign(VAlign_Center)
		.Padding(FMargin(20.f, 0.f, 0.f, 0.f))
		[
			SNew(STextBlock)
			.Font(MenuStyle->Font_40)
			.Text(NSLOCTEXT("SlAiMenu", "ChooseRecord", "ChooseRecord"))
		]
	+ SOverlay::Slot()
		.HAlign(HAlign_Right)
		.VAlign(VAlign_Center)
		.Padding(FMargin(0.f, 0.f, 20.f, 0.f))
		[
			SAssignNew(RecordComboBox, STextComboBox)
			.Font(MenuStyle->Font_30)
			.OptionsSource(&OptionsSource)
		]
		]


		];
	RecordComboBox->SetSelectedItem(OptionsSource[0]);

}
void SSlAiChooseRecordWidget::UpdateRecordName()
{
	SlAiDaTaHandle::Get()->RecordName = *RecordComboBox->GetSelectedItem().Get();
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
