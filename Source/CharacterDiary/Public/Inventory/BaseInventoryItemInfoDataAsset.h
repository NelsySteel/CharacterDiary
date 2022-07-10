// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Inventory/IInventoryItemInfoDataAsset.h"
#include "BaseInventoryItemInfoDataAsset.generated.h"


/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class CHARACTERDIARY_API UBaseInventoryItemInfoDataAsset : public UIInventoryItemInfoDataAsset
{
	GENERATED_BODY()
public:
	UBaseInventoryItemInfoDataAsset();
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ItemData")
		FString	Name;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ItemData")
		uint8	Weight;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ItemData")
		uint8	Cost;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ItemData")
		uint8	Amount;

};
