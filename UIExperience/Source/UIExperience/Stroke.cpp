// Fill out your copyright notice in the Description page of Project Settings.

#include "Stroke.h"
#include "Components/SplineMeshComponent.h"

// Sets default values
AStroke::AStroke()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AStroke::BeginPlay()
{
	Super::BeginPlay();

	LastUpdatedLocation = FVector::ZeroVector;
	LastUpdatedTangent = FVector::ZeroVector;
}

// Called every frame
void AStroke::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	TimeSinceLastUpdated += DeltaTime;
}

void AStroke::UpdateStroke(FVector CurrentCursorLocation, FVector CurrentCursorVelocity)
{
	FVector LocalCurrentCursorLocation = GetTransform().InverseTransformPosition(CurrentCursorLocation);
	FVector CurrentCursorTangent = TimeSinceLastUpdated * CurrentCursorVelocity;
	FVector LocalCurrentCursorTangent = GetTransform().InverseTransformVector(CurrentCursorTangent);

	if (FVector::Distance(LastUpdatedLocation, LocalCurrentCursorLocation) < MinDistanceThreshold) return;
	if (TimeSinceLastUpdated < MinUpdateTime) return;

	TimeSinceLastUpdated = 0;

	USplineMeshComponent* SplineMesh = CreateSpline();
	
	SplineMesh->SetStartAndEnd(LastUpdatedLocation, LastUpdatedTangent, LocalCurrentCursorLocation, LocalCurrentCursorTangent);
	LastUpdatedLocation = LocalCurrentCursorLocation;
	LastUpdatedTangent = LocalCurrentCursorTangent;
}

USplineMeshComponent* AStroke::CreateSpline()
{
	USplineMeshComponent* SplineMesh = NewObject<USplineMeshComponent>(this);
	SplineMesh->SetMobility(EComponentMobility::Movable);
	SplineMesh->AttachToComponent(GetRootComponent(), FAttachmentTransformRules::SnapToTargetIncludingScale);
	SplineMesh->SetStaticMesh(Mesh);
	SplineMesh->SetMaterial(0, Material);
	SplineMesh->RegisterComponent();
	return SplineMesh;
}
