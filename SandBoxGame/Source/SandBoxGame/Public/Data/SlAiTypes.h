// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Class.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class ECultureTeam:uint8
{
	EN = 0,
	ZH = 1,
};
namespace EMenuItem
{
	enum Type
	{
		NONE,
		StartGame,
		GameOption,
		QuitGame,
		NewGame,
		LoadRecord,
		StartGameGoBack,
		GameOptionGoBack,
		NewGameGoBack,
		ChooseRecordGoBack,
		EnterGame,
		EnterRecord


	};
}

namespace EMenuType
{
	enum Type
	{
		None,
		MainMenu,
		StartGame,
		GameOption,
		NewGame,
		ChooseRecord
	};
}
namespace EMenuAnim
{
	enum  Type
	{
		Stop,
		Close,
		Open
	};
}
//视角模式
namespace EGameViewMode {

	enum Type
	{
		First,
		Third
	};
}
//上半身动画的状态
namespace EUpperBody
{
	enum Type
	{
		None,
		Punch,
		Hit,
		Fight,
		PickUp,
		Eat

	};
}
//物品类型
namespace EObjectType
{
	enum Type
	{
		Normal=0,
		Food,
		Tool,
		Weapon
	};
}

//物品属性结构体
struct ObjectAttribute
{
	FText EN;
	FText ZH;
	EObjectType::Type ObjectType;
	int PlantAttack;
	int MetalAttack;
	int AnimalAttack;
	int AffectRange;
	FString TexPath;
	ObjectAttribute(const FText ENName, const FText ZHName,const EObjectType::Type OT,const int PA,const int MA,const int AA, const int AR,const FString TP)
	{
		EN = ENName;
		ZH = ZHName;
		ObjectType = OT;
		PlantAttack = PA;
		MetalAttack = MA;
		AnimalAttack = AA;
		AffectRange = AR;
		TexPath = TP;
	}

	FString ToString() {
		return EN.ToString() + FString("--") + ZH.ToString() + FString("--") + FString::FromInt((int)ObjectType) + FString("--") + FString::FromInt(PlantAttack) + FString("--") + FString::FromInt(MetalAttack) + FString("--") + FString::FromInt(AnimalAttack) + FString("--") + FString::FromInt(AffectRange) + FString("--") + TexPath;
	}
};
struct ShortcutContainer
{
	//物品ID
	int ObjectIndex;
	int ObjectNum;
	TSharedPtr<SBorder>ContainerBorder;
	TSharedPtr<SBorder>ObjectImage;
	TSharedPtr<STextBlock>ObjectNumText;
	const FSlateBrush* NormalContainerBrush;
	const FSlateBrush* ChoosedContainerBrush;
	TArray<const FSlateBrush*>*ObjectBrushList;


	ShortcutContainer(TSharedPtr<SBorder> CB, TSharedPtr<SBorder> OI, TSharedPtr<STextBlock> ONT, const FSlateBrush* NCB, const FSlateBrush* CCB, TArray<const FSlateBrush*>* OBL) {
		ContainerBorder = CB;
		ObjectImage = OI;
		ObjectNumText = ONT;
		NormalContainerBrush = NCB;
		ChoosedContainerBrush = CCB;
		ObjectBrushList = OBL;

		//初始化显示设置
		ObjectNum = 0;
		ObjectIndex = 0;
		ContainerBorder->SetBorderImage(NormalContainerBrush);
		ObjectImage->SetBorderImage((*ObjectBrushList)[0]);
	}

	//设置当前物品被选中图标，并且返回物品水印
	int SetChoosed(bool Option)
	{
		if (Option)
		{
			ContainerBorder->SetBorderImage(ChoosedContainerBrush);
		}
		else
		{
			ContainerBorder->SetBorderImage(NormalContainerBrush);
		}
		return ObjectIndex;
	}

	//设置Index以及更新笔刷
	ShortcutContainer* SetObject(int NewIndex)
	{
		ObjectIndex = NewIndex;
		ObjectImage->SetBorderImage((*ObjectBrushList)[ObjectIndex]);

		return this;
	}

	//设置数量
	ShortcutContainer*SetObjectNum(int Num=0)
	{
		ObjectNum = Num;

		if (ObjectNum==0||ObjectNum==1)
		{
			ObjectNumText->SetText(FString(""));
		}
		else
		{
			ObjectNumText->SetText(FString::FromInt(ObjectNum));
		}
		return this;
	}
};