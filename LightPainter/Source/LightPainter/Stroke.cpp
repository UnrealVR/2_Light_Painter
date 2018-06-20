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

}

void AStroke::Update(const FVector & CursorLocation)
{
	if (PreviousCursorLocation.IsNearlyZero())
	{
		PreviousCursorLocation = CursorLocation;
		return;
	}

	USplineMeshComponent* SplineMesh = CreateSplineMesh(CursorLocation);

	FVector LocalCursorLocation = SplineMesh->GetComponentTransform().InverseTransformPosition(CursorLocation);
	FVector LocalPreviousCursorLocation = SplineMesh->GetComponentTransform().InverseTransformPosition(PreviousCursorLocation);

	SplineMesh->SetStartAndEnd(LocalPreviousCursorLocation, FVector::ZeroVector, LocalCursorLocation, FVector::ZeroVector);

	PreviousCursorLocation = CursorLocation;
}

USplineMeshComponent* AStroke::CreateSplineMesh(const FVector & CursorLocation)
{
	USplineMeshComponent* SplineMesh = NewObject<USplineMeshComponent>(this);
	SplineMesh->SetMobility(EComponentMobility::Movable);
	SplineMesh->AttachToComponent(GetRootComponent(), FAttachmentTransformRules::SnapToTargetIncludingScale);
	SplineMesh->SetWorldLocation(CursorLocation);
	SplineMesh->SetStaticMesh(Mesh);
	SplineMesh->RegisterComponent();

	return SplineMesh;
}

