// Fill out your copyright notice in the Description page of Project Settings.

#include "VRPawnBase.h"

#include "Engine/World.h"
#include "Components/InputComponent.h"

// Sets default values
AVRPawnBase::AVRPawnBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SetRootComponent(CreateDefaultSubobject<USceneComponent>(TEXT("Root")));
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AVRPawnBase::BeginPlay()
{
	Super::BeginPlay();
	
	if (LeftHandControllerClass)
	{
		LeftHandController = GetWorld()->SpawnActor<AHandControllerBase>(LeftHandControllerClass);
		LeftHandController->AttachToComponent(GetRootComponent(), FAttachmentTransformRules::SnapToTargetIncludingScale);
	}

	if (RightHandControllerClass)
	{
		RightHandController = GetWorld()->SpawnActor<AHandControllerBase>(RightHandControllerClass);
		RightHandController->AttachToComponent(GetRootComponent(), FAttachmentTransformRules::SnapToTargetIncludingScale);
	}
}

void AVRPawnBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("RightTrigger", EInputEvent::IE_Pressed, this, &AVRPawnBase::RightTriggerPressed);
	PlayerInputComponent->BindAction("RightTrigger", EInputEvent::IE_Released, this, &AVRPawnBase::RightTriggerReleased);
}

// Called every frame
void AVRPawnBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


