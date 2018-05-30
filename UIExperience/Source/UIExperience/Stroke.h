// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Components/SplineComponent.h"

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

	void UpdateStroke(FVector CurrentCursorLocation);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	class USplineMeshComponent* CreateSpline();
	void GetLastStartAndEnd(FVector & StartPos, FVector & StartTangent, FVector & EndPos, FVector & EndTangent) const;

	// Configuration
	UPROPERTY(EditDefaultsOnly)
	class UStaticMesh* Mesh;

	UPROPERTY(EditDefaultsOnly)
	class UMaterialInterface* Material;

	UPROPERTY(EditDefaultsOnly)
	float MinDistanceThreshold = 5;

	// Components
	UPROPERTY(VisibleAnywhere)
	USplineComponent* Path;

	// State
	FVector LastUpdatedLocation;

};
