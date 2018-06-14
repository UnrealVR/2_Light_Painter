// Fill out your copyright notice in the Description page of Project Settings.

#include "PaintBrushHandController.h"
#include "Engine/World.h"

// Sets default values
APaintBrushHandController::APaintBrushHandController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StrokeSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("StrokeSpawnPoint"));
	StrokeSpawnPoint->SetupAttachment(GetRootComponent());

	WidgetInteractionComponent = CreateDefaultSubobject<UWidgetInteractionComponent>(TEXT("WidgetInteractionComponent"));
	WidgetInteractionComponent->SetupAttachment(GetRootComponent());
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

	FVector Velocity = (GetActorLocation() - LastLocation) / DeltaTime;
	LastLocation = GetActorLocation();

	if (CurrentStroke)
	{
		CurrentStroke->UpdateStroke(StrokeSpawnPoint->GetComponentLocation(), Velocity);
	}
}

void APaintBrushHandController::RightTriggerPressed()
{
	if (StrokeClass)
	{
		CurrentStroke = GetWorld()->SpawnActor<AStroke>(StrokeClass, StrokeSpawnPoint->GetComponentLocation(), FRotator::ZeroRotator);
	}
}

void APaintBrushHandController::RightTriggerReleased()
{
	CurrentStroke = nullptr;
}


