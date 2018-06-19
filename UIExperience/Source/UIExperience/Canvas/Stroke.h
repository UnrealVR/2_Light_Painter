// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Components/SplineComponent.h"
#include "Data/PaintingSaveGame.h"

#include "Stroke.generated.h"

/**
 * Represents a single stroke in the scene.
 *
 * The stroke is a spline mesh with many control points. Has methods for 
 * building the stroke up from cursor movement data.
 */
UCLASS()
class UIEXPERIENCE_API AStroke : public AActor
{
	GENERATED_BODY()
	
public:	
	AStroke();
	virtual void Tick(float DeltaTime) override;

	void UpdateStroke(FVector CurrentCursorLocation, FVector CurrentCursorVelocity);

	FStrokeData GetData() const;

	static AStroke* CreateFromData(UWorld* World, FStrokeData Stroke);

protected:
	virtual void BeginPlay() override;

private:

	void UpdatePendingSpline(FStrokeDataPoint ProvisionalPoint);
	FStrokeDataPoint MakePoint(FVector GlobalLocation, FVector GlobalVelocity) const;
	class USplineMeshComponent* CreateSplineStartingAtLastPoint();
	void AddSplinePoint(FStrokeDataPoint Point);

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
	TArray<FStrokeDataPoint> StrokePoints;

};
