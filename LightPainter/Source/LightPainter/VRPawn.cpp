// Fill out your copyright notice in the Description page of Project Settings.

#include "VRPawn.h"

#include "Engine/World.h"
#include "EngineUtils.h"

#include "Saving/PainterSaveGame.h"
#include "PaintingGameMode.h"

AVRPawn::AVRPawn()
{
	PrimaryActorTick.bCanEverTick = false;

	VRRoot = CreateDefaultSubobject<USceneComponent>(TEXT("VRRoot"));
	SetRootComponent(VRRoot);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(VRRoot);
}

void AVRPawn::BeginPlay()
{
	Super::BeginPlay();

	if (PaintBrushHandControllerClass)
	{
		RightHandController = GetWorld()->SpawnActor<AHandControllerBase>(PaintBrushHandControllerClass);
		RightHandController->AttachToComponent(GetRootComponent(), FAttachmentTransformRules::SnapToTargetIncludingScale);
		RightHandController->SetHand(EControllerHand::Right);
	}
	if (LeftHandControllerClass)
	{
		LeftHandController = GetWorld()->SpawnActor<AHandControllerBase>(LeftHandControllerClass);
		LeftHandController->AttachToComponent(GetRootComponent(), FAttachmentTransformRules::SnapToTargetIncludingScale);
		LeftHandController->SetHand(EControllerHand::Left);
	}
}

void AVRPawn::SetupPlayerInputComponent(UInputComponent * PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction(TEXT("RightTrigger"), EInputEvent::IE_Pressed, this, &AVRPawn::RightTriggerPressed);
	PlayerInputComponent->BindAction(TEXT("RightTrigger"), EInputEvent::IE_Released, this, &AVRPawn::RightTriggerReleased);

	PlayerInputComponent->BindAction(TEXT("Save"), EInputEvent::IE_Released, this, &AVRPawn::Save);

	PlayerInputComponent->BindAxis(TEXT("Paginate"), this, &AVRPawn::PaginateAxisInput);
}

void AVRPawn::Save()
{
	auto GameMode = Cast<APaintingGameMode>(GetWorld()->GetAuthGameMode());
	if (!GameMode) return;
	GameMode->SaveAndQuit();
}

void AVRPawn::PaginateAxisInput(float AxisValue)
{
	int Offset = 0;
	Offset += AxisValue < -0.9 ? -1 : 0;
	Offset += AxisValue > 0.9 ? 1 : 0;

	if (Offset != 0 && !PaginatedSinceReset)
	{
		Paginate(Offset);
		PaginatedSinceReset = true;
	}
	if (Offset == 0)
	{
		PaginatedSinceReset = false;
	}
}