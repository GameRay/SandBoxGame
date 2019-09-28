// Fill out your copyright notice in the Description page of Project Settings.


#include "SlAiPlayerCharacter.h"
#include "ConstructorHelpers.h"
#include "GameFramework/Character.h"
#include "Components/SkeletalMeshComponent.h"
#include"Classes/Components/CapsuleComponent.h"
#include"Classes/Components/InputComponent.h"
#include"Classes/GameFramework/Controller.h"
// Sets default values
ASlAiPlayerCharacter::ASlAiPlayerCharacter()
{
	GetCapsuleComponent()->SetCollisionProfileName(FName("PlayerProfile"));
	//第一人称Mesh
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> StaticMeshFirst(TEXT("SkeletalMesh'/Game/Res/PolygonAdventure/Mannequin/FirstPlayer/SkMesh/FirstPlayer.FirstPlayer'"));
	
	MeshFirst = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("MeshFirst"));
	MeshFirst->SetSkeletalMesh(StaticMeshFirst.Object);
	MeshFirst->SetupAttachment((USceneComponent*)GetCapsuleComponent());
	MeshFirst->bOnlyOwnerSee = true;
	MeshFirst->bCastDynamicShadow = false;
	MeshFirst->bReceivesDecals = false;

	//更新频率衰落
	MeshFirst->MeshComponentUpdateFlag = EMeshComponentUpdateFlag::OnlyTickPoseWhenRendered;
	MeshFirst->PrimaryComponentTick.TickGroup = TG_PrePhysics;
	
	MeshFirst->SetCollisionObjectType(ECC_Pawn);
	MeshFirst->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	MeshFirst->SetCollisionResponseToAllChannels(ECR_Ignore);
	MeshFirst->SetRelativeLocation(FVector(0.f, 0.f, -95.f));
	MeshFirst->SetRelativeRotation(FQuat::MakeFromEuler(FVector(0.f, 0.f, -90.f)));

	//加载第一人称动画蓝图
	UClass*FirstAnimInsClass = LoadClass<UAnimInstance>(NULL, TEXT("/Game/Blueprint/Player/FirstPlayer_Animationv.FirstPlayer_Animationv_C"));
	if (FirstAnimInsClass)
	{
		MeshFirst->AnimClass = FirstAnimInsClass;
	}
	//

	//第三人称Mesh
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ConstructorHelpers::FObjectFinder<USkeletalMesh> StaticMeshThird(TEXT("SkeletalMesh'/Game/Res/PolygonAdventure/Mannequin/Player/SkMesh/Player.Player'"));

	GetMesh()->SetSkeletalMesh(StaticMeshThird.Object);
	GetMesh()->bOnlyOwnerSee = true;
	GetMesh()->bReceivesDecals = false;
	GetMesh()->SetCollisionObjectType(ECC_Pawn);
	GetMesh()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	GetMesh()->SetCollisionResponseToChannels(ECR_Ignore);
	GetMesh()->SetRelativeLocation(FVector(0.f,0.f,-95.f));
	GetMesh()->SetRelativeRotation(FQuat::MakeFromEuler(FVector(0.f, 0.f, - 90.f)));

	//加载第三人称动画蓝图
	UClass*ThirdAnimInsClass = LoadClass<UAnimInstance>(NULL, TEXT("/Game/Blueprint/Player/ThirdPlayer_Animation.ThirdPlayer_Animation_C"));
	if (ThirdAnimInsClass)
	{
		GetMesh()->AnimClass = ThirdAnimInsClass;
	}


	//摄像机
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.f;
	CameraBoom->TargetOffset = FVector(0.f, 0.f, 60.f);
	CameraBoom->bUsePawnControlRotation = true;
	//第三人称
	ThirdCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("ThirdCamera"));
	ThirdCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);

	ThirdCamera->bUsePawnControlRotation = false;
	//第一人称
	FirstCamera= CreateDefaultSubobject<UCameraComponent>(TEXT("FirstCamera"));
	FirstCamera->SetupAttachment(RootComponent);
	FirstCamera->bUsePawnControlRotation = true;
	FirstCamera->AddLocalOffset(FVector(0.f, 0.f, 60.f));

	MeshFirst->SetVisibility(false);
	FirstCamera->SetActive(false);
	ThirdCamera->SetActive(true);
}

// Called when the game starts or when spawned
void ASlAiPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASlAiPlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASlAiPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward",this,&ASlAiPlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight",this,&ASlAiPlayerCharacter::MoveRight);



}

void ASlAiPlayerCharacter::MoveForward(float Value)
{
	if (Value!=0.f&&Controller)
	{
		const FRotator Rotation = Controller->GetControlRotation();
		FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::X);

		AddMovementInput(Direction,Value);
	}
}

void ASlAiPlayerCharacter::MoveRight(float Value)
{
	if (Value != 0.f&&Controller)
	{
		const FQuat Rotation = GetActorQuat();
		FVector Direction = FQuatRotationMatrix(Rotation).GetScaledAxis(EAxis::Y);

		AddMovementInput(Direction, Value);
	}
}

void ASlAiPlayerCharacter::LookUpAtRate(float Value)
{
}

void ASlAiPlayerCharacter::Turn(float Value)
{
}

void ASlAiPlayerCharacter::TurnAtRate(float Value)
{
}

void ASlAiPlayerCharacter::OnStartJump()
{
}

void ASlAiPlayerCharacter::OnStopJump()
{
}

void ASlAiPlayerCharacter::OnStartRun()
{
}

void ASlAiPlayerCharacter::OnStopRun()
{
}

