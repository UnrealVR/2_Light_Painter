// Fill out your copyright notice in the Description page of Project Settings.

#include "Stroke.h"
#include "Components/SplineMeshComponent.h"

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

	USplineMeshComponent* SplineMesh = CreateSpline();
	
	FVector StartPos, StartTangent, EndPos, EndTangent;
	GetLastStartAndEnd(StartPos, StartTangent, EndPos, EndTangent);

	SplineMesh->SetStartAndEnd(StartPos, StartTangent, EndPos, EndTangent);
}

USplineMeshComponent* AStroke::CreateSpline()
{
	USplineMeshComponent* SplineMesh = NewObject<USplineMeshComponent>(this);
	SplineMesh->SetMobility(EComponentMobility::Movable);
	SplineMesh->AttachToComponent(Path, FAttachmentTransformRules::KeepRelativeTransform);
	SplineMesh->SetStaticMesh(Mesh);
	SplineMesh->SetMaterial(0, Material);
	SplineMesh->RegisterComponent();
	return SplineMesh;
}

void AStroke::GetLastStartAndEnd(FVector& StartPos, FVector& StartTangent, FVector& EndPos, FVector& EndTangent) const
{
	int32 LastElemIndex = Path->GetNumberOfSplinePoints() - 1;

	Path->GetLocalLocationAndTangentAtSplinePoint(LastElemIndex - 1, StartPos, StartTangent);
	Path->GetLocalLocationAndTangentAtSplinePoint(LastElemIndex, EndPos, EndTangent);
}