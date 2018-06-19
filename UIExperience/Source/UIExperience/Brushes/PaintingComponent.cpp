// Fill out your copyright notice in the Description page of Project Settings.

#include "PaintingComponent.h"

#include "Engine/World.h"


// Sets default values for this component's properties
UPaintingComponent::UPaintingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPaintingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UPaintingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	FVector Velocity = (GetComponentLocation() - LastLocation) / DeltaTime;
	LastLocation = GetComponentLocation();

	if (CurrentStroke)
	{
		CurrentStroke->UpdateStroke(GetComponentLocation(), Velocity);
	}
}

void UPaintingComponent::StartBrushing()
{
	if (StrokeClass)
	{
		CurrentStroke = GetWorld()->SpawnActor<AStroke>(StrokeClass, GetComponentLocation(), FRotator::ZeroRotator);
	}
}

void UPaintingComponent::StopBrushing()
{
	CurrentStroke = nullptr;
}