// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Components/SplineMeshComponent.h"

#include "Stroke.generated.h"

UCLASS()
class LIGHTPAINTER_API AStroke : public AActor
{
	GENERATED_BODY()
	
public:	
	AStroke();
	virtual void Tick(float DeltaTime) override;

	void Update(const FVector& CursorLocation);

protected:
	virtual void BeginPlay() override;

private:
	USplineMeshComponent * CreateSplineMesh(const FVector & CursorLocation);

	// Config
	UPROPERTY(EditAnywhere)
	UStaticMesh* Mesh;

	UPROPERTY(EditAnywhere)
	float MaxStrokeTime = 0.2;

	// State
	FVector PreviousCursorLocation;

	float TimeSinceLastStroke;
};
