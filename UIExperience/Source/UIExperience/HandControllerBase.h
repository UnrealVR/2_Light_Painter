// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "MotionControllerComponent.h"

#include "HandControllerBase.generated.h"

UCLASS()
class UIEXPERIENCE_API AHandControllerBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHandControllerBase();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void RightTriggerPressed() {}
	virtual void RightTriggerReleased() {}

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	// Components
	UPROPERTY(VisibleAnywhere)
	UMotionControllerComponent* MotionController;

};
