// Fill out your copyright notice in the Description page of Project Settings.

#include "Stroke.h"
#include "Components/SplineMeshComponent.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"

AStroke::AStroke()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AStroke::BeginPlay()
{
	Super::BeginPlay();

	FStrokeDataPoint Point;
	Point.LocalLocation = FVector::ZeroVector;
	Point.LocalTangent = FVector::ZeroVector;
	StrokePoints.Add(Point);
	PendingSplineMesh = CreateSplineStartingAtLastPoint();
}

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
	for (FStrokeDataPoint Point : Stroke.StrokePoints)
	{
		StrokeActor->AddSplinePoint(Point);
	}
	return StrokeActor;
}

void AStroke::AddSplinePoint(FStrokeDataPoint Point)
{
	auto LastUpdatedLocation = StrokePoints.Last().LocalLocation;
	auto LastUpdatedTangent = StrokePoints.Last().LocalTangent;

	PendingSplineMesh->SetStartAndEnd(LastUpdatedLocation, LastUpdatedTangent, Point.LocalLocation, Point.LocalTangent);

	StrokePoints.Add(Point);

	PendingSplineMesh = CreateSplineStartingAtLastPoint();
}

void AStroke::UpdateStroke(FVector CurrentCursorLocation, FVector CurrentCursorVelocity)
{
	FStrokeDataPoint ProvisionalPoint = MakePoint(CurrentCursorLocation, CurrentCursorVelocity);

	UpdatePendingSpline(ProvisionalPoint);

	if (FVector::Distance(StrokePoints.Last().LocalLocation, ProvisionalPoint.LocalLocation) < MinDistanceThreshold) return;
	if (TimeSinceLastUpdated < MinUpdateTime) return;

	TimeSinceLastUpdated = 0;

	PendingSplineMesh = CreateSplineStartingAtLastPoint();

	StrokePoints.Add(ProvisionalPoint);
}

void AStroke::UpdatePendingSpline(FStrokeDataPoint ProvisionalPoint)
{
	FStrokeDataPoint LastUpdatedPoint = StrokePoints.Last();

	PendingSplineMesh->SetStartAndEnd(LastUpdatedPoint.LocalLocation, LastUpdatedPoint.LocalTangent, ProvisionalPoint.LocalLocation, ProvisionalPoint.LocalTangent);
}

FStrokeDataPoint AStroke::MakePoint(FVector GlobalLocation, FVector GlobalVelocity) const
{
	FVector CurrentCursorTangent = TimeSinceLastUpdated * GlobalVelocity;
	FStrokeDataPoint ProvisionalPoint;
	ProvisionalPoint.LocalLocation = GetTransform().InverseTransformPosition(GlobalLocation);
	ProvisionalPoint.LocalTangent = GetTransform().InverseTransformVector(CurrentCursorTangent);
	return ProvisionalPoint;
}

USplineMeshComponent* AStroke::CreateSplineStartingAtLastPoint()
{
	USplineMeshComponent* SplineMesh = NewObject<USplineMeshComponent>(this);
	SplineMesh->SetMobility(EComponentMobility::Movable);
	SplineMesh->AttachToComponent(GetRootComponent(), FAttachmentTransformRules::SnapToTargetIncludingScale);
	SplineMesh->SetStaticMesh(Mesh);
	SplineMesh->SetMaterial(0, Material);
	SplineMesh->SetMaterial(1, Material);
	SplineMesh->RegisterComponent();
	SplineMesh->SetCollisionProfileName("OverlapAllDynamic");

	auto LastUpdatedLocation = StrokePoints.Last().LocalLocation;
	auto LastUpdatedTangent = StrokePoints.Last().LocalTangent;
	SplineMesh->SetStartAndEnd(LastUpdatedLocation, LastUpdatedTangent, LastUpdatedLocation, LastUpdatedTangent);
	return SplineMesh;
}
