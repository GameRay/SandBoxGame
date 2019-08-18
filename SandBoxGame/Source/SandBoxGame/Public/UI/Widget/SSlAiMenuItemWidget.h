// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include"Public/Data/SlAiTypes.h"
#include"SlAiMenuWidgetStyle.h"
#include"SlAiStyle.h"


DECLARE_DELEGATE_OneParam(FItemClicked,const EMenuItem::Type)
/**
 * 
 */
class SANDBOXGAME_API SSlAiMenuItemWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SSlAiMenuItemWidget)
	{}
	SLATE_EVENT(FItemClicked, OnClicked)
		SLATE_ATTRIBUTE(FText, ItemText)
		SLATE_ATTRIBUTE(EMenuItem::Type, ItemType)
		SLATE_END_ARGS()


	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);
	virtual FReply OnMouseButtonDown(const FGeometry&MyGeometry,const FPointerEvent&MouseEvent)override;
	virtual FReply OnMouseButtonUp(const FGeometry&MyGeometry, const FPointerEvent&MouseEvent)override;
	virtual void OnMouseLeave(const FPointerEvent&MouseEvent) override;
private:
	FSlateColor GetTinColor()const;
private:
	const struct FSlAiMenuStyle*MenuStyle;
	FItemClicked OnClicked;
	EMenuItem::Type ItemType;

	bool IsMouseButtonDown;
};
