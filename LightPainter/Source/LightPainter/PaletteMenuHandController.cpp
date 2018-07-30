// Fill out your copyright notice in the Description page of Project Settings.

#include "PaletteMenuHandController.h"


APaletteMenuHandController::APaletteMenuHandController()
{
	HandMenu = CreateDefaultSubobject<UWidgetComponent>(TEXT("HandMenu"));
	HandMenu->SetupAttachment(GetRootComponent());
}


