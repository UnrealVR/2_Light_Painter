// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Camera/CameraComponent.h"
#include "HandControllerBase.h"

#include "VRPawnBase.generated.h"


/**
 * The base class for all VR Pawns.
 *
 * Spawns left and right hand controllers of the given type. Will also direct input to theses.
 */
UCLASS()
class UIEXPERIENCE_API AVRPawnBase : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AVRPawnBase();
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//Components
	UPROPERTY(VisibleAnywhere)
	AHandControllerBase* LeftHandController;

	UPROPERTY(VisibleAnywhere)
	AHandControllerBase* RightHandController;


private:
	void RightTriggerPressed() { if (RightHandController) RightHandController->RightTriggerPressed(); }
	void RightTriggerReleased() { if (RightHandController) RightHandController->RightTriggerReleased(); }

	//COmponetns
	UPROPERTY(VisibleAnywhere)
	UCameraComponent* Camera;

	//Config
	UPROPERTY(EditAnywhere)
	TSubclassOf<AHandControllerBase> LeftHandControllerClass;

	UPROPERTY(EditAnywhere)
	TSubclassOf<AHandControllerBase> RightHandControllerClass;


};
