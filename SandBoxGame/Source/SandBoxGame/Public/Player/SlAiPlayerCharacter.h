// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "SlAiPlayerCharacter.generated.h"

UCLASS()
class SANDBOXGAME_API ASlAiPlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASlAiPlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
private:
	void MoveForward(float Value);
	void MoveRight(float Value);
	void LookUpAtRate(float Value);
	void Turn(float Value);
	void TurnAtRate(float Value);
	void OnStartJump();
	void OnStopJump();
	void OnStartRun();
	void OnStopRun();
public:
	UPROPERTY(VisibleDefaultsOnly, Category = "SlAi")
	USpringArmComponent*CameraBoom;
	UPROPERTY(VisibleDefaultsOnly, Category = "SlAi")
	UCameraComponent*ThirdCamera;
	UPROPERTY(VisibleDefaultsOnly, Category = "SlAi")
	UCameraComponent*FirstCamera;
private:
	UPROPERTY(VisibleDefaultsOnly, Category = "SlAi")
		USkeletalMeshComponent*MeshFirst;

};
