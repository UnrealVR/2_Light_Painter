// Fill out your copyright notice in the Description page of Project Settings.

#include "PaintBrushHandController.h"
#include "Engine/World.h"

// Sets default values
APaintBrushHandController::APaintBrushHandController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	WidgetInteractionComponent = CreateDefaultSubobject<UWidgetInteractionComponent>(TEXT("WidgetInteractionComponent"));
	WidgetInteractionComponent->SetupAttachment(GetRootComponent());
}

// Called when the game starts or when spawned
void APaintBrushHandController::BeginPlay()
{
	Super::BeginPlay();

	SetState(EBrushMode::Painting);
}

// Called every frame
void APaintBrushHandController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	TickUIButtonPressDetection();
}

EBrushMode APaintBrushHandController::GetState() const
{
	if (!CurrentBrush) return EBrushMode::NONE;
	return CurrentBrush->GetState();
}

void APaintBrushHandController::SetState(EBrushMode NewState)
{
	// TODO: Compare with class referencing approach.
	for (auto Component : GetComponents())
	{
		auto Brush = Cast<IVRBrushInterface>(Component);
		if (!Brush) continue;
		if (Brush->GetState() == NewState)
		{
			if (CurrentBrush) CurrentBrush->SetActive(false);
			Brush->SetActive(true);
			CurrentBrush = Brush;
		}
	}
}

void APaintBrushHandController::TickUIButtonPressDetection()
{
	auto HitResult = WidgetInteractionComponent->GetLastHitResult();
	bool ShouldClick = WidgetInteractionComponent->IsOverInteractableWidget() && HitResult.Distance < ClickDistance;
	if (ShouldClick)
	{
		WidgetInteractionComponent->PressPointerKey(EKeys::LeftMouseButton);
		UIButtonIsPressed = true;
	}
	else if (UIButtonIsPressed)
	{
		WidgetInteractionComponent->ReleasePointerKey(EKeys::LeftMouseButton);
	}
}

void APaintBrushHandController::RightTriggerPressed()
{
	if (CurrentBrush) CurrentBrush->StartBrushing();
}

void APaintBrushHandController::RightTriggerReleased()
{
	if (CurrentBrush) CurrentBrush->StopBrushing();
}


