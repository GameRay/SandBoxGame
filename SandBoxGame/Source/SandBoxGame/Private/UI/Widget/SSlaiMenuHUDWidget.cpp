// Fill out your copyright notice in the Description page of Project Settings.


#include "SSlaiMenuHUDWidget.h"
#include "SlateOptMacros.h"
#include"SlAiStyle.h"
#include"SImage.h"
#include"SlAiMenuWidgetStyle.h"
#include"SlateWidgetStyleAsset.h"
#include"SOverlay.h"
#include"Engine.h"
#include"SDPIScaler.h"
//#include"Internationalization.h"
#define LOCTEXT_NAMESPACE "SSlaiMenuHUDWidget"
BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SSlaiMenuHUDWidget::Construct(const FArguments& InArgs)
{
	UIScaler.Bind(this,&SSlaiMenuHUDWidget::GetUIScaler);
	MenuStyle = &SlAiStyle::Get().GetWidgetStyle<FSlAiMenuStyle>("BPSlAiMenuStyle");
	
	//UE_LOG(LogTemp,Warning,TEXT("jl %s"), *MenuStyle->MenuBackgroundBrush.GetResourceObject()->GetFName().ToString());
	//UE_LOG(LogTemp, Warning, TEXT("jl %s"), *StylEb.GetResourceObject()->GetFName().ToString());
	if (MenuStyle)
	{
		ChildSlot
			[
				SNew(SDPIScaler)
				.DPIScale(UIScaler)
				[
					SNew(SOverlay)
					+ SOverlay::Slot()
					.HAlign(HAlign_Fill)
					.VAlign(VAlign_Fill)
					[
						SNew(SImage)
					//.Image(SlAiStyle::Get().GetBrush("JLBPS"))
						.Image(&MenuStyle->MenuHUDBackgroundBrush)
					]
					+ SOverlay::Slot()
						//.Expose(ImageSlot)
						.HAlign(HAlign_Center)
						.VAlign(VAlign_Center)
					[
						/*SNew(SImage)
						.Image(&MenuStyle->MenuBackgroundBrush)*/
						SAssignNew(MenuWidget,SSlAiMenuWidget)
					]


					/*+ SOverlay::Slot()
						.HAlign(HAlign_Left)
						.VAlign(VAlign_Top)
						
						[
							SNew(SButton)
							.OnClicked(this, &SSlaiMenuHUDWidget::OnClick)
							.RenderTransform(FTransform2D(FScale2D(2,1)))
							.Text(LOCTEXT("dianjianniu","点击"))
						]*/

				]	
			];
	}
	

}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
float SSlaiMenuHUDWidget::GetUIScaler()const
{
	return GetViewportSize().Y / 1080.0;
}
FVector2D SSlaiMenuHUDWidget::GetViewportSize()const
{
	FVector2D Result(1920,1080);
	if (GEngine&&GEngine->GameViewport)
	{
		GEngine->GameViewport->GetViewportSize(Result);
	}
	return Result;
}
//FReply SSlaiMenuHUDWidget::OnClick()
//{
//
//	ImageSlot->HAlign(HAlign_Right).VAlign(VAlign_Bottom);
//	return FReply::Handled();
//}
#undef LOCTEXT_NAMESPACE