// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "IInventoryComponentLogic.h"
#include "BaseInfoInventoryLogic.generated.h"

class UBaseInventoryItemInfoDataAsset;
/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class CHARACTERDIARY_API UBaseInfoInventoryLogic : public UIInventoryComponentLogic
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, Category="data")
	UBaseInventoryItemInfoDataAsset* GetData();
};
