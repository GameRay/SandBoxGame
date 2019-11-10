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
//�ӽ�ģʽ
namespace EGameViewMode {

	enum Type
	{
		First,
		Third
	};
}
//�ϰ�������״̬
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
//��Ʒ����
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

//��Ʒ���Խṹ��
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
	//��ƷID
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

		//��ʼ����ʾ����
		ObjectNum = 0;
		ObjectIndex = 0;
		ContainerBorder->SetBorderImage(NormalContainerBrush);
		ObjectImage->SetBorderImage((*ObjectBrushList)[0]);
	}

	//���õ�ǰ��Ʒ��ѡ��ͼ�꣬���ҷ�����Ʒˮӡ
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

	//����Index�Լ����±�ˢ
	ShortcutContainer* SetObject(int NewIndex)
	{
		ObjectIndex = NewIndex;
		ObjectImage->SetBorderImage((*ObjectBrushList)[ObjectIndex]);

		return this;
	}

	//��������
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