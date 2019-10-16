// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SlAiPlayerCharacter.h"
#include "SlAiPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class SANDBOXGAME_API ASlAiPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	ASlAiPlayerController();
	virtual void Tick(float DeltaSeconds)override;
	
	
protected:
	virtual void BeginPlay()override;
	virtual void SetupInputComponent()override;
public:
	ASlAiPlayerCharacter*SPCharacter;

private:
	void ChangeView();
	void LeftEventStart();
	void LeftEventStop();
	void RightEventStart();
	void RightEventStop();


	
};
