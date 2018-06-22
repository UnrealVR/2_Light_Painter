// Fill out your copyright notice in the Description page of Project Settings.

#include "Stroke.h"

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
}

// Called every frame
void AStroke::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	TimeSinceLastStroke += DeltaTime;
}

void AStroke::Update(FVector CursorLocation, FVector CursorVelocity)
{
	if (!PendingSpline)
	{
		CommitPendingSpline(CursorLocation, CursorVelocity);
		return;
	}

	UpdatePendingSpline(CursorLocation, CursorVelocity);

	if (TimeSinceLastStroke > MaxStrokeTime)
	{
		CommitPendingSpline(CursorLocation, CursorVelocity);
	}
}

void AStroke::CommitPendingSpline(FVector CursorLocation, FVector CursorVelocity)
{
	PendingSpline = CreateSplineMesh(CursorLocation);

	PreviousCursorLocation = CursorLocation;
	PreviousCursorVelocity = CursorVelocity;
	TimeSinceLastStroke = 0;

	UpdatePendingSpline(CursorLocation, CursorVelocity);
}

void AStroke::UpdatePendingSpline(FVector CursorLocation, FVector CursorVelocity)
{
	FVector LocalCursorLocation = PendingSpline->GetComponentTransform().InverseTransformPosition(CursorLocation);
	FVector LocalPreviousCursorLocation = PendingSpline->GetComponentTransform().InverseTransformPosition(PreviousCursorLocation);
	FVector LocalCursorVelocity = PendingSpline->GetComponentTransform().InverseTransformVector(CursorVelocity);
	FVector LocalPreviousCursorVelocity = PendingSpline->GetComponentTransform().InverseTransformVector(PreviousCursorVelocity);
	FVector LocalCursorTangent = LocalCursorVelocity * TimeSinceLastStroke;
	FVector LocalPreviousCursorTangent = PreviousCursorVelocity * TimeSinceLastStroke;

	PendingSpline->SetStartAndEnd(LocalPreviousCursorLocation, LocalPreviousCursorTangent, LocalCursorLocation, LocalCursorTangent);
}

USplineMeshComponent* AStroke::CreateSplineMesh(FVector CursorLocation)
{
	USplineMeshComponent* SplineMesh = NewObject<USplineMeshComponent>(this);
	SplineMesh->SetMobility(EComponentMobility::Movable);
	SplineMesh->AttachToComponent(GetRootComponent(), FAttachmentTransformRules::SnapToTargetIncludingScale);
	SplineMesh->SetWorldLocation(CursorLocation);
	SplineMesh->SetStaticMesh(Mesh);
	SplineMesh->RegisterComponent();

	return SplineMesh;
}

