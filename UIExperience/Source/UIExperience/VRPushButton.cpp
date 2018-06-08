// Fill out your copyright notice in the Description page of Project Settings.

#include "VRPushButton.h"


// Sets default values for this component's properties
UVRPushButton::UVRPushButton()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	ButtonConstraint = CreateDefaultSubobject<UPhysicsConstraintComponent>(TEXT("ButtonConstraint"));
	ButtonConstraint->SetupAttachment(this);
}


// Called when the game starts
void UVRPushButton::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UVRPushButton::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

