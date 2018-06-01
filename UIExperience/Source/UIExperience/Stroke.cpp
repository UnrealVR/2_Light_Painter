// Fill out your copyright notice in the Description page of Project Settings.

#include "Stroke.h"
#include "Components/SplineMeshComponent.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"

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

	FStrokeDataPoints Point;
	Point.LocalLocation = FVector::ZeroVector;
	Point.LocalTangent = FVector::ZeroVector;
	StrokePoints.Add(Point);
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
	Stroke.StrokePoints = StrokePoints;
	return Stroke;
}

AStroke* AStroke::CreateFromData(UWorld * World, FStrokeData Stroke)
{
	AStroke* StrokeActor = World->SpawnActor<AStroke>(Stroke.TheClass, Stroke.Transform);
	StrokeActor->Material = Stroke.Material;
	for (FStrokeDataPoints Point : Stroke.StrokePoints)
	{
		StrokeActor->AddSplinePoint(Point);
	}
	return StrokeActor;
}

void AStroke::AddSplinePoint(FStrokeDataPoints Point)
{
	auto LastUpdatedLocation = StrokePoints.Last().LocalLocation;
	auto LastUpdatedTangent = StrokePoints.Last().LocalTangent;

	PendingSplineMesh->SetStartAndEnd(LastUpdatedLocation, LastUpdatedTangent, Point.LocalLocation, Point.LocalTangent);

	StrokePoints.Add(Point);
	UE_LOG(LogTemp, Warning, TEXT("Lent:%d"), StrokePoints.Num());

	PendingSplineMesh = CreateSpline();
}

void AStroke::UpdateStroke(FVector CurrentCursorLocation, FVector CurrentCursorVelocity)
{
	FVector LocalCurrentCursorLocation = GetTransform().InverseTransformPosition(CurrentCursorLocation);
	FVector CurrentCursorTangent = TimeSinceLastUpdated * CurrentCursorVelocity;
	FVector LocalCurrentCursorTangent = GetTransform().InverseTransformVector(CurrentCursorTangent);

	auto LastUpdatedLocation = StrokePoints.Last().LocalLocation;
	auto LastUpdatedTangent = StrokePoints.Last().LocalTangent;

	PendingSplineMesh->SetStartAndEnd(LastUpdatedLocation, LastUpdatedTangent, LocalCurrentCursorLocation, LocalCurrentCursorTangent);

	if (FVector::Distance(LastUpdatedLocation, LocalCurrentCursorLocation) < MinDistanceThreshold) return;
	if (TimeSinceLastUpdated < MinUpdateTime) return;

	TimeSinceLastUpdated = 0;

	PendingSplineMesh = CreateSpline();

	FStrokeDataPoints Point;
	Point.LocalLocation = LocalCurrentCursorLocation;
	Point.LocalTangent = LocalCurrentCursorTangent;
	StrokePoints.Add(Point);
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
	auto LastUpdatedLocation = StrokePoints.Last().LocalLocation;
	auto LastUpdatedTangent = StrokePoints.Last().LocalTangent;
	SplineMesh->SetStartAndEnd(LastUpdatedLocation, LastUpdatedTangent, LastUpdatedLocation, LastUpdatedTangent);
	return SplineMesh;
}
