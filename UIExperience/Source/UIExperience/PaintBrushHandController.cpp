// Fill out your copyright notice in the Description page of Project Settings.

#include "PaintBrushHandController.h"
#include "Engine/World.h"

// Sets default values
APaintBrushHandController::APaintBrushHandController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MotionController = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("MotionController"));
	SetRootComponent(MotionController);
	MotionController->SetShowDeviceModel(true);
	MotionController->SetTrackingSource(EControllerHand::Right);
}

// Called when the game starts or when spawned
void APaintBrushHandController::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void APaintBrushHandController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (CurrentStroke)
	{
		CurrentStroke->UpdateStroke(GetActorLocation());
	}
}

void APaintBrushHandController::RightTriggerPressed()
{
	if (StrokeClass)
	{
		CurrentStroke = GetWorld()->SpawnActor<AStroke>(StrokeClass, GetActorLocation(), FRotator::ZeroRotator);
	}
}

void APaintBrushHandController::RightTriggerReleased()
{
	CurrentStroke = nullptr;
}


