// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "MotionControllerComponent.h"

#include "HandController.generated.h"

UCLASS()
class LIGHTPAINTER_API AHandController : public AActor
{
	GENERATED_BODY()
	
public:	
	AHandController();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

private:
	// Components
	UPROPERTY(VisibleAnywhere)
	UMotionControllerComponent* MotionController;

};
