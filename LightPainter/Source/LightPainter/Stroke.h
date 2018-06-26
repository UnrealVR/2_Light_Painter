// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Stroke.generated.h"

UCLASS()
class LIGHTPAINTER_API AStroke : public AActor
{
	GENERATED_BODY()
	
public:	
	AStroke();

	void Update(FVector CursorLocation);

private:
	class USplineMeshComponent* CreateSplineMesh();

	// Components
	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root;

	// Config
	UPROPERTY(EditDefaultsOnly)
	UStaticMesh* SplineMesh;

	UPROPERTY(EditDefaultsOnly)
	UMaterialInterface* SplineMaterial;

	// State
	FVector PreviousCursorLocation;
};
