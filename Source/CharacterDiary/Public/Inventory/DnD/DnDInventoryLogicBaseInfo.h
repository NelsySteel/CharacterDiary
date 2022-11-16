// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../IInventoryComponentLogic.h"
#include "DnDInventoryLogicBaseInfo.generated.h"


class UBaseInventoryItemInfoObject;
/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class CHARACTERDIARY_API UDnDInventoryLogicBaseInfo : public UIInventoryComponentLogic
{
	GENERATED_BODY()
public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ItemData")
		FString	Name;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ItemData")
		uint8	Weight;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ItemData")
		uint8	Cost;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ItemData")
		uint8	Amount;
protected:
	virtual bool LoadFromXML(FXmlNode* rootNode) override;
};

