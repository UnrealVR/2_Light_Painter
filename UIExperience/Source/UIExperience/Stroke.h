// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
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
	
};
