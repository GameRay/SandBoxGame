// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include"SBox.h"
#include"SlAiMenuWidgetStyle.h"
#include"STextBlock.h"
#include"VerticalBox.h"
#include"SSlAiMenuItemWidget.h"
#include"SlAiDaTaHandle.h"
#include"SlAiTypes.h"
#include"SSlAiGameOptionWidget.h"
#include"SSlAiNewGameWidget.h"
#include"SSlAiChooseRecordWidget.h"
/*
 * 
 */

struct MenuGroup
{
	FText MenuName;
	float MenuHeight;
	TArray<TSharedPtr<SCompoundWidget>> ChildWidget;
	MenuGroup(FText Name, float Height, TArray<TSharedPtr<SCompoundWidget>>*Children)
	{
		MenuName = Name;
		MenuHeight = Height;
		ChildWidget = *Children;
	}
};


class SANDBOXGAME_API SSlAiMenuWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SSlAiMenuWidget)
	{}
	SLATE_END_ARGS()

		
	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);
	virtual void Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime) override;
private:
	void MenuItemOnClicked(EMenuItem::Type ItemType);
	void ChangeCulture(ECultureTeam culture);
	void ChangeVolume(float Music, float Sound);
	//初始化所有空间
	void InitializeMenuList();
	void ChooseWidget(EMenuType::Type WidgetType);

	void ResetWidgetSize(float NewWidget,float  NewHeight);

	void InitializedAnimation();

	void PlayClose(EMenuType::Type NewMenu);
private:
	const struct FSlAiMenuStyle*MenuStyle;
	TSharedPtr<SBox>RootSizeBox;
	TSharedPtr<STextBlock>TitleText;
	TSharedPtr<SVerticalBox>ContentBox;
	//保存菜单组
	TMap<EMenuType::Type, TSharedPtr<MenuGroup>> MenuMap;

	TSharedPtr<SSlAiGameOptionWidget> GameOptionWidget;
	TSharedPtr<SSlAiNewGameWidget> NewGameWidget;
	TSharedPtr<SSlAiChooseRecordWidget> ChooseRecordWidget;

	FCurveSequence MenuAnimation;
	FCurveHandle MenuCurve;
	float CurrentHeight;
	bool IsMenuShow;
	bool ControlLocked;
	EMenuAnim::Type AnimState;
	EMenuType::Type CurrentMenu;

};
