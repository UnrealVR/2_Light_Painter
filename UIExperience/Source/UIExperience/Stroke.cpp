// Fill out your copyright notice in the Description page of Project Settings.

#include "Stroke.h"


// Sets default values
AStroke::AStroke()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Path = CreateDefaultSubobject<USplineComponent>(TEXT("Path"));
	Path->SetDrawDebug(true);
	SetRootComponent(Path);
}

// Called when the game starts or when spawned
void AStroke::BeginPlay()
{
	Super::BeginPlay();

	Path->ClearSplinePoints(false);
	Path->AddSplinePoint(GetActorLocation(), ESplineCoordinateSpace::World);
}

// Called every frame
void AStroke::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AStroke::UpdateStroke(FVector CurrentCursorLocation)
{
	Path->AddSplinePoint(CurrentCursorLocation, ESplineCoordinateSpace::World);
}

