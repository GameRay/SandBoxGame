// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include"STextBlock.h"
#include"SUniformGridPanel.h"
/**
 * 
 */
class SANDBOXGAME_API SSlAiShotrCutWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SSlAiShotrCutWidget)
	{}
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);
	virtual void Tick(const FGeometry&AllottedGeometry, const double InCurrentTime, const float InDeltaTime)override;
private:
	//初始化所有容器
	void InitializeContainer();
private:
	const struct FSlAiGameStyle*GameStyle;
	//物品信息指针
	TSharedPtr<STextBlock> ShortcutInfoTextBlock;
	//网格指针
	TSharedPtr<SUniformGridPanel>GridPanel;

	//是否初始化容器
	bool IsInitializeContainer;

};
