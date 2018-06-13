// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Components/WidgetComponent.h"


#include "MainMenu.generated.h"

UCLASS()
class UIEXPERIENCE_API AMainMenu : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMainMenu();

	void AddSlot();
	void ClickedItem(FString ItemID);
	void BeginDelete();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	void OpenLevel(FString ItemID);
	void DeleteItem(FString ItemID);

	class USaveGameList* GetSaveGameList() const;
	class UPaintingListSaveGameButtons* GetSaveGameListButtons() const;

	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root;

	UPROPERTY(VisibleAnywhere)
	UWidgetComponent* Menu;

	UPROPERTY(VisibleAnywhere)
	UWidgetComponent* MenuButtons;

	// State
	bool DeleteMode = false;
	
};
