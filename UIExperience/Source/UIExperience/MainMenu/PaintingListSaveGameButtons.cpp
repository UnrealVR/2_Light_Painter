// Fill out your copyright notice in the Description page of Project Settings.

#include "PaintingListSaveGameButtons.h"


bool UPaintingListSaveGameButtons::Initialize()
{
	if (!Super::Initialize()) return false;
	CreateNewButton->OnClicked.AddDynamic(this, &UPaintingListSaveGameButtons::CreatNewButtonClicked);
	return true;
}


