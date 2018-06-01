// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Camera/CameraComponent.h"
#include "HandControllerBase.h"

#include "VRPawn.generated.h"


UCLASS()
class UIEXPERIENCE_API AVRPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AVRPawn();
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//Components
	UPROPERTY(VisibleAnywhere)
	AHandControllerBase* RightHandController;

private:
	void RightTriggerPressed() { RightHandController->RightTriggerPressed(); }
	void RightTriggerReleased() { RightHandController->RightTriggerReleased(); }

	//COmponetns
	UPROPERTY(VisibleAnywhere)
	UCameraComponent* Camera;

	//Config
	UPROPERTY(EditAnywhere)
	TSubclassOf<AHandControllerBase> RightHandControllerClass;


};
