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
};