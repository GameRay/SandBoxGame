// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Styling/SlateWidgetStyle.h"
#include "SlateWidgetStyleContainerBase.h"
#include"SlateBrush.h"
#include "SlAiGameWidgetStyle.generated.h"

/**
 * 
 */
USTRUCT()
struct SANDBOXGAME_API FSlAiGameStyle : public FSlateWidgetStyle
{
	GENERATED_USTRUCT_BODY()

	FSlAiGameStyle();
	virtual ~FSlAiGameStyle();

	// FSlateWidgetStyle
	virtual void GetResources(TArray<const FSlateBrush*>& OutBrushes) const override;
	static const FName TypeName;
	virtual const FName GetTypeName() const override { return TypeName; };
	static const FSlAiGameStyle& GetDefault();


	//字体和颜色
	UPROPERTY(EditAnywhere, Category = "Menu")
		FSlateFontInfo Font_60;
	UPROPERTY(EditAnywhere, Category = "Menu")
		FSlateFontInfo Font_Outline_50;
	UPROPERTY(EditAnywhere, Category = "Menu")
		FSlateFontInfo Font_40;
	UPROPERTY(EditAnywhere, Category = "Menu")
		FSlateFontInfo Font_Outline_40;
	UPROPERTY(EditAnywhere, Category = "Menu")
		FSlateFontInfo Font_30;
	UPROPERTY(EditAnywhere, Category = "Menu")
		FSlateFontInfo Font_20;
	UPROPERTY(EditAnywhere, Category = "Menu")
		FSlateFontInfo Font_Outline_20;
	UPROPERTY(EditAnywhere, Category = "Menu")
		FSlateFontInfo Font_Outline_16;
	UPROPERTY(EditAnywhere, Category = "Menu")
		FSlateFontInfo Font_16;
	UPROPERTY(EditAnywhere, Category = "Menu")
		FLinearColor FontColor_White;
	UPROPERTY(EditAnywhere, Category = "Menu")
		FLinearColor FontColor_Black;
	///图标笔刷
	//指定快捷栏的容器图标,把快捷栏的Style指定到Package
	UPROPERTY(EditAnywhere, Category = Package)
		FSlateBrush NormalContainerBrush;

	//指定被选择的容器的Brush
	UPROPERTY(EditAnywhere, Category = Package)
		FSlateBrush ChoosedContainerBrush;
	//
	UPROPERTY(EditAnywhere, Category = Package)
		FSlateBrush EmptyBrush;
};

/**
 */
UCLASS(hidecategories=Object, MinimalAPI)
class USlAiGameWidgetStyle : public USlateWidgetStyleContainerBase
{
	GENERATED_BODY()

public:
	/** The actual data describing the widget appearance. */
	UPROPERTY(Category=Appearance, EditAnywhere, meta=(ShowOnlyInnerProperties))
	FSlAiGameStyle WidgetStyle;

	virtual const struct FSlateWidgetStyle* const GetStyle() const override
	{
		return static_cast< const struct FSlateWidgetStyle* >( &WidgetStyle );
	}
};
