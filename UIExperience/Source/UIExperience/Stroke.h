// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Components/SplineComponent.h"
#include "Data/PaintingSaveGame.h"

#include "Stroke.generated.h"

UCLASS()
class UIEXPERIENCE_API AStroke : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AStroke();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void UpdateStroke(FVector CurrentCursorLocation, FVector CurrentCursorVelocity);

	FStrokeData GetData() const;

	static AStroke* CreateFromData(UWorld* World, FStrokeData Stroke);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	class USplineMeshComponent* CreateSpline();
	void AddSplinePoint(FStrokeDataPoints Point);

	// Configuration
	UPROPERTY(EditDefaultsOnly)
	class UStaticMesh* Mesh;

	UPROPERTY(EditDefaultsOnly)
	class UMaterialInterface* Material;

	UPROPERTY(EditDefaultsOnly)
	float MinDistanceThreshold = 1;
	UPROPERTY(EditDefaultsOnly)
	float MinUpdateTime = 0.1;


	// State
	float TimeSinceLastUpdated = 0;
	USplineMeshComponent* PendingSplineMesh;
	TArray<FStrokeDataPoints> StrokePoints;

};
