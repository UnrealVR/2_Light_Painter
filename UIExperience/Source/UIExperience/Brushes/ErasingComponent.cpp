// Fill out your copyright notice in the Description page of Project Settings.

#include "ErasingComponent.h"

#include "Components/PrimitiveComponent.h"

UErasingComponent::UErasingComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UErasingComponent::StartBrushing()
{
	auto Collider = Cast<UPrimitiveComponent>(GetChildComponent(0));
	if (!Collider) return;
	TSet<AActor *> OverlappingActors;
	Collider->GetOverlappingActors(OverlappingActors);
	for (auto Actor : OverlappingActors)
	{
		Actor->Destroy();
	}
}

void UErasingComponent::StopBrushing()
{
}