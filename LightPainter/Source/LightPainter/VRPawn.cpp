// Fill out your copyright notice in the Description page of Project Settings.

#include "VRPawn.h"

#include "Engine/World.h"

AVRPawn::AVRPawn()
{
	PrimaryActorTick.bCanEverTick = false;

	VRRoot = CreateDefaultSubobject<USceneComponent>(TEXT("VRRoot"));
	SetRootComponent(VRRoot);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(GetRootComponent());
}

void AVRPawn::BeginPlay()
{
	Super::BeginPlay();
	
	if (RightHandControllerClass)
	{
		RightHandController = GetWorld()->SpawnActor<APaintBrushHandController>(RightHandControllerClass);
		RightHandController->AttachToComponent(GetRootComponent(), FAttachmentTransformRules::SnapToTargetIncludingScale);
	}
}

void AVRPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

