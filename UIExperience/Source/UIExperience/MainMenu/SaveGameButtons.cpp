// Fill out your copyright notice in the Description page of Project Settings.

#include "SaveGameButtons.h"


bool USaveGameButtons::Initialize()
{
	if (!Super::Initialize()) return false;
	CreateNewButton->OnClicked.AddDynamic(this, &USaveGameButtons::CreateNewButtonClicked);
	DeleteButton->OnClicked.AddDynamic(this, &USaveGameButtons::DeleteButtonClicked);
	PrevPageButton->OnClicked.AddDynamic(this, &USaveGameButtons::PrevPage);
	NextPageButton->OnClicked.AddDynamic(this, &USaveGameButtons::NextPage);
	return true;
}


