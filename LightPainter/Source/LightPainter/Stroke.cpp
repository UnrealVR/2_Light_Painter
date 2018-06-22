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
	if (PreviousCursorLocation.IsNearlyZero())
	{
		PreviousCursorLocation = CursorLocation;
		return;
	}

	if (TimeSinceLastStroke < MaxStrokeTime) return;

	USplineMeshComponent* SplineMesh = CreateSplineMesh(CursorLocation);

	FVector LocalCursorLocation = SplineMesh->GetComponentTransform().InverseTransformPosition(CursorLocation);
	FVector LocalPreviousCursorLocation = SplineMesh->GetComponentTransform().InverseTransformPosition(PreviousCursorLocation);
	FVector LocalCursorVelocity = SplineMesh->GetComponentTransform().InverseTransformVector(CursorVelocity);
	FVector LocalPreviousCursorVelocity = SplineMesh->GetComponentTransform().InverseTransformVector(PreviousCursorVelocity);
	FVector LocalCursorTangent = LocalCursorVelocity * TimeSinceLastStroke;
	FVector LocalPreviousCursorTangent = PreviousCursorVelocity * TimeSinceLastStroke;

	SplineMesh->SetStartAndEnd(LocalPreviousCursorLocation, LocalPreviousCursorTangent, LocalCursorLocation, LocalCursorTangent);

	PreviousCursorLocation = CursorLocation;
	PreviousCursorVelocity = CursorVelocity;
	TimeSinceLastStroke = 0;
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

