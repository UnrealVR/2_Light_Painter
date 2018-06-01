// Fill out your copyright notice in the Description page of Project Settings.

#include "Stroke.h"
#include "Components/SplineMeshComponent.h"
#include "Engine/World.h"

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
	PendingSplineMesh = CreateSpline();
}

// Called every frame
void AStroke::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	TimeSinceLastUpdated += DeltaTime;
}

FStrokeData AStroke::GetData() const
{
	FStrokeData Stroke;
	Stroke.Material = Material;
	Stroke.TheClass = GetClass();
	Stroke.Transform = GetActorTransform();
	return Stroke;
}

AStroke* AStroke::CreateFromData(UWorld * World, FStrokeData Stroke)
{
	AStroke* StrokeActor = World->SpawnActor<AStroke>(Stroke.TheClass, Stroke.Transform);
	StrokeActor->Material = Stroke.Material;
	return StrokeActor;
}

void AStroke::UpdateStroke(FVector CurrentCursorLocation, FVector CurrentCursorVelocity)
{
	FVector LocalCurrentCursorLocation = GetTransform().InverseTransformPosition(CurrentCursorLocation);
	FVector CurrentCursorTangent = TimeSinceLastUpdated * CurrentCursorVelocity;
	FVector LocalCurrentCursorTangent = GetTransform().InverseTransformVector(CurrentCursorTangent);

	PendingSplineMesh->SetStartAndEnd(LastUpdatedLocation, LastUpdatedTangent, LocalCurrentCursorLocation, LocalCurrentCursorTangent);

	if (FVector::Distance(LastUpdatedLocation, LocalCurrentCursorLocation) < MinDistanceThreshold) return;
	if (TimeSinceLastUpdated < MinUpdateTime) return;

	TimeSinceLastUpdated = 0;

	PendingSplineMesh = CreateSpline();

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
	SplineMesh->SetMaterial(1, Material);
	SplineMesh->RegisterComponent();
	SplineMesh->SetStartAndEnd(LastUpdatedLocation, LastUpdatedTangent, LastUpdatedLocation, LastUpdatedTangent);
	return SplineMesh;
}
