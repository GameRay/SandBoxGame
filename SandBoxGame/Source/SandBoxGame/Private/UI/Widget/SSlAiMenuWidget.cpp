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
#include"SlAiMenuController.h"
#include "SlAiHelper.h"


#define LOCTEXT_NAMESPACE "SSlAiMenuWidget"
BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SSlAiMenuWidget::Construct(const FArguments& InArgs)
{
	MenuStyle = &SlAiStyle::Get().GetWidgetStyle<FSlAiMenuStyle>("BPSlAiMenuStyle");
	FSlateApplication::Get().PlaySound(MenuStyle->MenuBackGroundMusic);
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
	InitializedAnimation();
}

void SSlAiMenuWidget::Tick(const FGeometry & AllottedGeometry, const double InCurrentTime, const float InDeltaTime)
{

	switch (AnimState)
	{
	case EMenuAnim::Stop:
		break;
	case EMenuAnim::Close:
		if (MenuAnimation.IsPlaying())
		{
			ResetWidgetSize(MenuCurve.GetLerp()*600.f ,-1.f);
			if (MenuCurve.GetLerp()<0.6f&&IsMenuShow)
			{
				ChooseWidget(EMenuType::None);
			}
			
		}
		else
		{
			AnimState = EMenuAnim::Open;
			MenuAnimation.Play(this->AsShared());
		}
		break;
	case EMenuAnim::Open:
		if (MenuAnimation.IsPlaying())
		{
			ResetWidgetSize(MenuCurve.GetLerp()*600.f, CurrentHeight);
			if (MenuCurve.GetLerp() >0.6f&&!IsMenuShow)
			{
				ChooseWidget(CurrentMenu);
			}

		}
		else
		{
			AnimState = EMenuAnim::Stop;
			ControlLocked = false;
		}
		break;
	default:
		break;
	}
}

void SSlAiMenuWidget::MenuItemOnClicked(EMenuItem::Type ItemType)
{
	//TitleText->SetText(NSLOCTEXT("SlAiMenu","StartGame","StartGame"));

	if (ControlLocked)
	{
		return;
	}
	ControlLocked = true;
	switch (ItemType)
	{
	/*case EMenuItem::NONE:
		PlayClose(EMenuType::None);
		break;*/
	case EMenuItem::StartGame:
		PlayClose(EMenuType::StartGame);
		break;
	case EMenuItem::GameOption:
		PlayClose(EMenuType::GameOption);
		break;
	case EMenuItem::QuitGame:
		ControlLocked = false;
		SlAiHelper::PlayerSoundAndCall<SSlAiMenuWidget>(GWorld,MenuStyle->ExitGameSound,this,&SSlAiMenuWidget::QuitGame);
		//QuitGame();
		break;
	case EMenuItem::NewGame:
		PlayClose(EMenuType::NewGame);
		break;
	case EMenuItem::LoadRecord:
		PlayClose(EMenuType::ChooseRecord);
		break;
	case EMenuItem::StartGameGoBack:
		PlayClose(EMenuType::MainMenu);
		break;
	case EMenuItem::GameOptionGoBack:
		PlayClose(EMenuType::MainMenu);
		break;
	case EMenuItem::NewGameGoBack:
		PlayClose(EMenuType::StartGame);
		break;
	case EMenuItem::ChooseRecordGoBack:
		PlayClose(EMenuType::StartGame);
		break;
	case EMenuItem::EnterGame:
		//ControlLocked = false;
		if (NewGameWidget->AllowEnterGame())
		{
			SlAiHelper::PlayerSoundAndCall(GWorld, MenuStyle->StartGameSound, this, &SSlAiMenuWidget::EnterGame);
			//EnterGame();
		}
		else
		{
			ControlLocked = false;
		}
		
		break;
	case EMenuItem::EnterRecord:
		ChooseRecordWidget->UpdateRecordName();
		SlAiHelper::PlayerSoundAndCall(GWorld, MenuStyle->StartGameSound, this, &SSlAiMenuWidget::EnterGame);
		break;
	default:
		break;
	}
	
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
	NewGameList.Add(SNew(SSlAiMenuItemWidget).ItemText(NSLOCTEXT("SlAiMenu", "EnterGame", "EnterGame")).ItemType(EMenuItem::EnterGame).OnClicked(this, &SSlAiMenuWidget::MenuItemOnClicked));
	NewGameList.Add(SNew(SSlAiMenuItemWidget).ItemText(NSLOCTEXT("SlAiGame", "GoBack", "GoBack")).ItemType(EMenuItem::StartGameGoBack).OnClicked(this, &SSlAiMenuWidget::MenuItemOnClicked));
	MenuMap.Add(EMenuType::NewGame, MakeShareable(new MenuGroup(NSLOCTEXT("SlAiMenu", "NewGame", "NewGame"), 510.f, &NewGameList)));


	//选择存档
	TArray<TSharedPtr<SCompoundWidget>> ChooseRecordList;
	SAssignNew(ChooseRecordWidget, SSlAiChooseRecordWidget);

	ChooseRecordList.Add(ChooseRecordWidget);
	ChooseRecordList.Add(SNew(SSlAiMenuItemWidget).ItemText(NSLOCTEXT("SlAiMenu", "EnterRecord", "EnterRecord")).ItemType(EMenuItem::EnterGame).OnClicked(this, &SSlAiMenuWidget::MenuItemOnClicked));
	ChooseRecordList.Add(SNew(SSlAiMenuItemWidget).ItemText(NSLOCTEXT("SlAiGame", "GoBack", "GoBack")).ItemType(EMenuItem::StartGameGoBack).OnClicked(this, &SSlAiMenuWidget::MenuItemOnClicked));
	MenuMap.Add(EMenuType::ChooseRecord, MakeShareable(new MenuGroup(NSLOCTEXT("SlAiMenu", "LoadRecord", "LoadRecord"), 510.f, &ChooseRecordList)));

	ChooseWidget(EMenuType::MainMenu);
}
void SSlAiMenuWidget::ChooseWidget(EMenuType::Type WidgetType)
{
	IsMenuShow = WidgetType != EMenuType::None;
	ContentBox->ClearChildren();
	if (WidgetType ==EMenuType::None)
	{
		return;
	}
	if (!MenuMap.Find(WidgetType))
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
void SSlAiMenuWidget::InitializedAnimation()
{
	const float StartDelay = 0.3f;
	const float AnimDuration = 0.6f;
	MenuAnimation = FCurveSequence();
	MenuCurve = MenuAnimation.AddCurve(StartDelay, AnimDuration, ECurveEaseFunction::QuadInOut);

	ResetWidgetSize(600.f, 510.f);

	ChooseWidget(EMenuType::MainMenu);

	ControlLocked = false;
	AnimState = EMenuAnim::Stop;
	MenuAnimation.JumpToEnd();

}
void SSlAiMenuWidget::PlayClose(EMenuType::Type NewMenu)
{
	CurrentMenu = NewMenu;
	CurrentHeight = (*MenuMap.Find(NewMenu))->MenuHeight;
	AnimState = EMenuAnim::Close;
	MenuAnimation.PlayReverse(this->AsShared());

	FSlateApplication::Get().PlaySound(MenuStyle->MenuItemChangeGameSound);
}
void SSlAiMenuWidget::QuitGame()
{
	//UKismetSystemLibrary::QuitGame(GWorld, UGameplayStatics::GetPlayerController(GWorld, 0), EQuitPreference::Quit,false);
	APlayerController * PlayerController =UGameplayStatics::GetPlayerController(GWorld, 0);
	if (PlayerController)
	{
		PlayerController->ConsoleCommand("quit");
	}
}
void SSlAiMenuWidget::EnterGame()
{
	SlAiHelper::DEBUG("111111111111");
	UGameplayStatics::OpenLevel(GWorld, FName("GameMap"));
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
#undef LOCTEXT_NAMESPACE
