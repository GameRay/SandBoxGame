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
	//��ʼ����������
	void InitializeContainer();
private:
	const struct FSlAiGameStyle*GameStyle;
	//��Ʒ��Ϣָ��
	TSharedPtr<STextBlock> ShortcutInfoTextBlock;
	//����ָ��
	TSharedPtr<SUniformGridPanel>GridPanel;

	//�Ƿ��ʼ������
	bool IsInitializeContainer;

};
