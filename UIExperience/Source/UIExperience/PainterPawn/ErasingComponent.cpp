// Fill out your copyright notice in the Description page of Project Settings.

#include "ErasingComponent.h"


// Sets default values for this component's properties
UErasingComponent::UErasingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UErasingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UErasingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UErasingComponent::StartBrushing()
{
}

void UErasingComponent::StopBrushing()
{
}