// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include"Data/SlAiTypes.h"
#include"STextBlock.h"
#include "SlAiPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class SANDBOXGAME_API ASlAiPlayerState : public APlayerState
{
	GENERATED_BODY()
public:
	ASlAiPlayerState();
	void RegisterShortCutContainer(TArray<TSharedPtr<ShortcutContainer>>*ContainerList, TSharedPtr<STextBlock>ShortcutInfoTextBlock);

private:
	FText GetShortcutInfoText() const;
private:

	TArray<TSharedPtr<ShortcutContainer>>ShortcutContainerList;
	TAttribute<FText>ShortcutInfoTextAttr;
};
