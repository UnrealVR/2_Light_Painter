// Fill out your copyright notice in the Description page of Project Settings.

#include "VRPawn.h"

#include "Components/InputComponent.h"
#include "Engine/World.h"

// Sets default values
AVRPawn::AVRPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SetRootComponent(CreateDefaultSubobject<USceneComponent>(TEXT("Root")));
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(RootComponent);

	WidgetInteractionComponent = CreateDefaultSubobject<UWidgetInteractionComponent>(TEXT("WidgetInteractionComponent"));
	WidgetInteractionComponent->SetupAttachment(Camera);
}

// Called when the game starts or when spawned
void AVRPawn::BeginPlay()
{
	Super::BeginPlay();
	
	if (RightHandControllerClass)
	{
		RightHandController = GetWorld()->SpawnActor<APaintBrushHandController>(RightHandControllerClass);
		RightHandController->AttachToComponent(GetRootComponent(), FAttachmentTransformRules::SnapToTargetIncludingScale);
	}
}

// Called every frame
void AVRPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AVRPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("RightTrigger", EInputEvent::IE_Pressed, this, &AVRPawn::RightTriggerPressed);
	PlayerInputComponent->BindAction("RightTrigger", EInputEvent::IE_Released, this, &AVRPawn::RightTriggerReleased);
}

