// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Styling/SlateWidgetStyle.h"
#include "SlateWidgetStyleContainerBase.h"
#include "SlateBrush.h"
#include"SlateFontInfo.h"
#include "SlAiMenuWidgetStyle.generated.h"


/**
 * 
 */
USTRUCT()
struct SANDBOXGAME_API FSlAiMenuStyle : public FSlateWidgetStyle
{
	GENERATED_USTRUCT_BODY()

	FSlAiMenuStyle();
	virtual ~FSlAiMenuStyle();

	// FSlateWidgetStyle
	virtual void GetResources(TArray<const FSlateBrush*>& OutBrushes) const override;
	static const FName TypeName;
	virtual const FName GetTypeName() const override { return TypeName; };
	static const FSlAiMenuStyle& GetDefault();
	UPROPERTY(EditAnywhere, Category = "Menu")
	FSlateBrush MenuHUDBackgroundBrush;
	UPROPERTY(EditAnywhere, Category = "Menu")
	FSlateBrush MenuBackgroundBrush;
	UPROPERTY(EditAnywhere, Category = "Menu")
	FSlateBrush LeftIconBrush;
	UPROPERTY(EditAnywhere, Category = "Menu")
	FSlateBrush RightIconBrush;
	UPROPERTY(EditAnywhere, Category = "Menu")
	FSlateBrush TitleBorderBrush;
	UPROPERTY(EditAnywhere, Category = "Menu")
	FSlateBrush MenuItemBrush;
	UPROPERTY(EditAnywhere, Category = "Menu")
	FSlateFontInfo Font_60;
	UPROPERTY(EditAnywhere, Category = "Menu")
	FSlateFontInfo Font_40;
	UPROPERTY(EditAnywhere, Category = "Menu")
	FSlateFontInfo Font_30;
	UPROPERTY(EditAnywhere, Category = "Menu")
	FSlateBrush GameOptionBrush;
	UPROPERTY(EditAnywhere, Category = "Menu")
	FLinearColor FontColor_White;
	UPROPERTY(EditAnywhere, Category = "Menu")
	FLinearColor FontColor_Black;

	UPROPERTY(EditAnywhere, Category = "Menu")
	FSlateBrush CheckedBoxBrush;
	UPROPERTY(EditAnywhere, Category = "Menu")
	FSlateBrush UnCheckedBoxBrush;


};

/**
 */
UCLASS(hidecategories=Object, MinimalAPI)
class USlAiMenuWidgetStyle : public USlateWidgetStyleContainerBase
{
	GENERATED_BODY()

public:
	/** The actual data describing the widget appearance. */
	UPROPERTY(Category=Appearance, EditAnywhere, meta=(ShowOnlyInnerProperties))
	FSlAiMenuStyle WidgetStyle;

	virtual const struct FSlateWidgetStyle* const GetStyle() const override
	{
		return static_cast< const struct FSlateWidgetStyle* >( &WidgetStyle );
	}
};
