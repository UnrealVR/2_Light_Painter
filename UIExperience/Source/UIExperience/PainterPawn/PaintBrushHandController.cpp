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

	SetState(EBrushState::Painting);
}

// Called every frame
void APaintBrushHandController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	TickButtonPressDetection();
}

EBrushState APaintBrushHandController::GetState() const
{
	if (!CurrentBrush) return EBrushState::NONE;
	return CurrentBrush->GetState();
}

void APaintBrushHandController::SetState(const EBrushState & NewState)
{
	for (auto Component : GetComponents())
	{
		auto Brush = Cast<IVRBrushInterface>(Component);
		if (!Brush) continue;
		if (Brush->GetState() == NewState)
		{
			if (CurrentBrush) CurrentBrush->Activate(false);
			Brush->Activate(true);
			CurrentBrush = Brush;
		}
	}
}

void APaintBrushHandController::TickButtonPressDetection()
{
	auto HitResult = WidgetInteractionComponent->GetLastHitResult();
	bool ShouldClick = WidgetInteractionComponent->IsOverInteractableWidget() && HitResult.Distance < ClickDistance;
	if (ShouldClick)
	{
		WidgetInteractionComponent->PressPointerKey(EKeys::LeftMouseButton);
		ButtonIsPressed = true;
	}
	else if (ButtonIsPressed)
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


