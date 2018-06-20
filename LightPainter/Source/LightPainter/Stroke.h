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
	virtual void Tick(float DeltaTime) override;

	void Update(const FVector& CursorLocation);

protected:
	virtual void BeginPlay() override;

private:
	// Config
	UPROPERTY(EditAnywhere)
	UStaticMesh* Mesh;

};
