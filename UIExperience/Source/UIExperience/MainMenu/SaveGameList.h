// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "Components/UniformGridPanel.h"

#include "SaveGameList.generated.h"

/**
 * 
 */
UCLASS()
class UIEXPERIENCE_API USaveGameList : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	bool Initialize() override;

private:
	UPROPERTY(meta = (BindWidget))
	UUniformGridPanel* Grid;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class USaveGameItem> SaveGameItemClass;
};
