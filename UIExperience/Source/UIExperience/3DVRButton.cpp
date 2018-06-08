// Fill out your copyright notice in the Description page of Project Settings.

#include "3DVRButton.h"


// Sets default values
A3DVRButton::A3DVRButton()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Collider = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Collider"));
	SetRootComponent(Collider);

	Widget = CreateDefaultSubobject<UWidgetComponent>(TEXT("Widget"));
	Widget->SetupAttachment(Collider);
}

// Called when the game starts or when spawned
void A3DVRButton::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void A3DVRButton::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

