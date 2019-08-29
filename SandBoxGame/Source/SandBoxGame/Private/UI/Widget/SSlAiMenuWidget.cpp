// Fill out your copyright notice in the Description page of Project Settings.


#include "SSlAiMenuWidget.h"
#include "SlateOptMacros.h"
#include"SlAiStyle.h"
#include"Public/Widgets/DeclarativeSyntaxSupport.h"
#include"SOverlay.h"
#include"SImage.h"
#include"SBorder.h"
#include"Internationalization.h"
#include"SSlAiMenuItemWidget.h"
#include"SlAiTypes.h"
#include"Common/SlAiHelper.h"
#include"UI/Widget/SSlAiGameOptionWidget.h"
#include "SSlAiNewGameWidget.h"
#include "SSlAiChooseRecordWidget.h"


#define LOCTEXT_NAMESPACE "SSlAiMenuWidget"
BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SSlAiMenuWidget::Construct(const FArguments& InArgs)
{
	MenuStyle = &SlAiStyle::Get().GetWidgetStyle<FSlAiMenuStyle>("BPSlAiMenuStyle");
	
	FInternationalization::Get().SetCurrentCulture(TEXT("zh"));
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
			+SOverlay::Slot()
				.HAlign(HAlign_Center)
				.VAlign(VAlign_Top)
				.Padding(FMargin(0.f,130.f,0.f,0.f))
				[
					SAssignNew(ContentBox,SVerticalBox)
				]
			]
		
		];
	

	InitializeMenuList();
}

void SSlAiMenuWidget::MenuItemOnClicked(EMenuItem::Type)
{
	//TitleText->SetText(NSLOCTEXT("SlAiMenu","StartGame","StartGame"));
}
void SSlAiMenuWidget::ChangeCulture(ECultureTeam culture)
{
	SlAiDaTaHandle::Get()->ChangeLocalizationCulture(culture);
}
void SSlAiMenuWidget::ChangeVolume(float Music, float Sound)
{
	SlAiDaTaHandle::Get()->ResetMenuVolume(Music,Sound);
}
void SSlAiMenuWidget::InitializeMenuList()
{
	//ContentBox->AddSlot()
	//	[
	//		/*SNew(SSlAiMenuItemWidget)
	//		.ItemText(NSLOCTEXT("SlAiMenu", "StartGame", "StartGame"))
	//		.ItemType(EMenuItem::StartGame)
	//	.OnClicked(this, &SSlAiMenuWidget::MenuItemOnClicked)*/

	//	//SNew(SSlAiGameOptionWidget)
	//	//.ChangeCulture(this,&SSlAiMenuWidget::ChangeCulture)
	//	//.ChangeVolume(this,&SSlAiMenuWidget::ChangeVolume)
	//		SNew(SSlAiChooseRecordWidget)
	//	];

	TArray<TSharedPtr<SCompoundWidget>>MainMenuList;
	MainMenuList.Add(SNew(SSlAiMenuItemWidget).ItemText(NSLOCTEXT("SlAiMenu", "StartGame", "StartGame")).ItemType(EMenuItem::StartGame).OnClicked(this, &SSlAiMenuWidget::MenuItemOnClicked));
	MainMenuList.Add(SNew(SSlAiMenuItemWidget).ItemText(NSLOCTEXT("SlAiMenu", "GameOption", "GameOption")).ItemType(EMenuItem::GameOption).OnClicked(this, &SSlAiMenuWidget::MenuItemOnClicked));
	MainMenuList.Add(SNew(SSlAiMenuItemWidget).ItemText(NSLOCTEXT("SlAiMenu", "QuitGame", "QuitGame")).ItemType(EMenuItem::QuitGame).OnClicked(this, &SSlAiMenuWidget::MenuItemOnClicked));

	MenuMap.Add(EMenuType::MainMenu, MakeShareable(new MenuGroup(NSLOCTEXT("SlAiMenu", "Menu", "Menu"),510.f,&MainMenuList)));

	TArray<TSharedPtr<SCompoundWidget>>StartGameList;
	StartGameList.Add(SNew(SSlAiMenuItemWidget).ItemText(NSLOCTEXT("SlAiMenu", "NewGame", "NewGame")).ItemType(EMenuItem::NewGame).OnClicked(this, &SSlAiMenuWidget::MenuItemOnClicked));
	StartGameList.Add(SNew(SSlAiMenuItemWidget).ItemText(NSLOCTEXT("SlAiMenu", "LoadRecord", "LoadRecord")).ItemType(EMenuItem::LoadRecord).OnClicked(this, &SSlAiMenuWidget::MenuItemOnClicked));
	StartGameList.Add(SNew(SSlAiMenuItemWidget).ItemText(NSLOCTEXT("SlAiGame", "GoBack", "GoBack")).ItemType(EMenuItem::StartGameGoBack).OnClicked(this, &SSlAiMenuWidget::MenuItemOnClicked));
	//MenuGroup a =  MenuGroup(NSLOCTEXT("SlAiMenu", "Menu", "Menu"), 510.f, &StartGameList);
	MenuMap.Add(EMenuType::StartGame, MakeShareable(new MenuGroup(NSLOCTEXT("SlAiMenu", "StartGame", "StartGame"), 510.f, &StartGameList)));

	//设置
	TArray<TSharedPtr<SCompoundWidget>> GameOptionList;
	SAssignNew(GameOptionWidget, SSlAiGameOptionWidget)
		.ChangeCulture(this, &SSlAiMenuWidget::ChangeCulture)
		.ChangeVolume(this, &SSlAiMenuWidget::ChangeVolume);
	GameOptionList.Add(GameOptionWidget);
	GameOptionList.Add(SNew(SSlAiMenuItemWidget).ItemText(NSLOCTEXT("SlAiGame", "GoBack", "GoBack")).ItemType(EMenuItem::StartGameGoBack).OnClicked(this, &SSlAiMenuWidget::MenuItemOnClicked));

	MenuMap.Add(EMenuType::GameOption,MakeShareable(new MenuGroup(NSLOCTEXT("SlAiMenu", "GameOption", "GameOption"),510.f,&GameOptionList)));

	//新游戏
	TArray<TSharedPtr<SCompoundWidget>> NewGameList;
	SAssignNew(NewGameWidget, SSlAiNewGameWidget);

	NewGameList.Add(NewGameWidget);
	NewGameList.Add(SNew(SSlAiMenuItemWidget).ItemText(NSLOCTEXT("SlAiMenu", "EnterGame", "EnterGame")).ItemType(EMenuItem::StartGameGoBack).OnClicked(this, &SSlAiMenuWidget::MenuItemOnClicked));
	NewGameList.Add(SNew(SSlAiMenuItemWidget).ItemText(NSLOCTEXT("SlAiGame", "GoBack", "GoBack")).ItemType(EMenuItem::StartGameGoBack).OnClicked(this, &SSlAiMenuWidget::MenuItemOnClicked));
	MenuMap.Add(EMenuType::GameOption, MakeShareable(new MenuGroup(NSLOCTEXT("SlAiMenu", "NewGame", "NewGame"), 510.f, &NewGameList)));


	//选择存档
	TArray<TSharedPtr<SCompoundWidget>> ChooseRecordList;
	SAssignNew(ChooseRecordWidget, SSlAiChooseRecordWidget);

	ChooseRecordList.Add(ChooseRecordWidget);
	ChooseRecordList.Add(SNew(SSlAiMenuItemWidget).ItemText(NSLOCTEXT("SlAiMenu", "EnterRecord", "EnterRecord")).ItemType(EMenuItem::StartGameGoBack).OnClicked(this, &SSlAiMenuWidget::MenuItemOnClicked));
	ChooseRecordList.Add(SNew(SSlAiMenuItemWidget).ItemText(NSLOCTEXT("SlAiGame", "GoBack", "GoBack")).ItemType(EMenuItem::StartGameGoBack).OnClicked(this, &SSlAiMenuWidget::MenuItemOnClicked));
	MenuMap.Add(EMenuType::GameOption, MakeShareable(new MenuGroup(NSLOCTEXT("SlAiMenu", "LoadRecord", "LoadRecord"), 510.f, &NewGameList)));

	ChooseWidget(EMenuType::MainMenu);
}
void SSlAiMenuWidget::ChooseWidget(EMenuType::Type WidgetType)
{
	ContentBox->ClearChildren();
	if (WidgetType ==EMenuType::None)
	{
		return;
	}
	for (TArray<TSharedPtr<SCompoundWidget>>::TIterator It((*MenuMap.Find(WidgetType))->ChildWidget) ; It  ;++It)
	{
		ContentBox->AddSlot().AutoHeight()
			[
				(*It)->AsShared()
			];
	}
	TitleText->SetText((*MenuMap.Find(WidgetType))->MenuName);

	ResetWidgetSize(600.f, (*MenuMap.Find(WidgetType))->MenuHeight);
}
void SSlAiMenuWidget::ResetWidgetSize(float NewWidget, float NewHeight)
{
	if (NewWidget>0)
	{
		RootSizeBox->SetWidthOverride(NewWidget);
	}
	if (NewHeight > 0)
	{
		RootSizeBox->SetHeightOverride(NewHeight);
	}
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
#undef LOCTEXT_NAMESPACE
