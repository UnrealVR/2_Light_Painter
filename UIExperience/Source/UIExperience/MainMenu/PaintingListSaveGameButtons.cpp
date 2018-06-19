// Fill out your copyright notice in the Description page of Project Settings.

#include "PaintingListSaveGameButtons.h"


bool UPaintingListSaveGameButtons::Initialize()
{
	if (!Super::Initialize()) return false;
	CreateNewButton->OnClicked.AddDynamic(this, &UPaintingListSaveGameButtons::CreateNewButtonClicked);
	DeleteButton->OnClicked.AddDynamic(this, &UPaintingListSaveGameButtons::DeleteButtonClicked);
	PrevPageButton->OnClicked.AddDynamic(this, &UPaintingListSaveGameButtons::PrevPage);
	NextPageButton->OnClicked.AddDynamic(this, &UPaintingListSaveGameButtons::NextPage);
	return true;
}


