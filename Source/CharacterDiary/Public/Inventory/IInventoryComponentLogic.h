// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "IInventoryComponentLogic.generated.h"


class UIInventoryItemInfoDataAsset;
/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class CHARACTERDIARY_API UIInventoryComponentLogic : public UObject
{
	GENERATED_BODY()
public:
	UIInventoryComponentLogic() = default;
	~UIInventoryComponentLogic() = default;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Data")
	UIInventoryItemInfoDataAsset* data;
};
