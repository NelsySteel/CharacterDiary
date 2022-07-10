// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "IInventoryItemInfoDataAsset.generated.h"

/**
 * 
 */
class UIInventoryComponentLogic;
UCLASS(BlueprintType, Blueprintable)
class CHARACTERDIARY_API UIInventoryItemInfoDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ItemData")
	FString LogicName;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ItemData")
	TSubclassOf<UIInventoryComponentLogic> LogicClass;

};
