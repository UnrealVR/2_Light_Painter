// Fill out your copyright notice in the Description page of Project Settings.

#include "3DVRButton.h"

#include "Engine/World.h"
#include "Kismet/KismetSystemLibrary.h"

const auto BUTTON_TRACE_CHANNEL = ECollisionChannel::ECC_GameTraceChannel1;

// Sets default values
A3DVRButton::A3DVRButton()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	Widget = CreateDefaultSubobject<UWidgetComponent>(TEXT("Widget"));
	Widget->SetupAttachment(Root);

	TriggerPlaneWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("TriggerPlaneWidget"));
	TriggerPlaneWidget->SetupAttachment(Root);

	TraceStart = CreateDefaultSubobject<UArrowComponent>(TEXT("TraceStart"));
	TraceStart->SetupAttachment(Root);
}

// Called when the game starts or when spawned
void A3DVRButton::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void A3DVRButton::Tick(float DeltaTime)
{
	FVector Start = TraceStart->GetComponentLocation();
	FVector End = GetActorLocation();
	FQuat Rot = TraceStart->GetComponentQuat();
	FCollisionShape Shape = FCollisionShape::MakeBox(FVector(TraceDepth / 2, TraceRadius, TraceRadius));
	auto Params = FCollisionQueryParams::DefaultQueryParam;
	Params.AddIgnoredActor(this);

	FHitResult HitResult;
	bool Hit = GetWorld()->SweepSingleByChannel(HitResult, Start, End, Rot, BUTTON_TRACE_CHANNEL, Shape, Params);
	UKismetSystemLibrary::DrawDebugArrow(this, Start, End, 2, FLinearColor::Red);

	if (Hit)
	{
		Widget->SetWorldLocation(HitResult.Location);
	} 
	else 
	{
		Widget->SetWorldLocation(End);
	}
}

