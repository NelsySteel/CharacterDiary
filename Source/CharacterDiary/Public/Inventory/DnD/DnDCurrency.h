// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/UserDefinedStruct.h"
#include "Inventory/BaseCurrency.h"
#include "DnDCurrency.generated.h"

/**
 * 
 */
UENUM(Blueprintable, BlueprintType)
enum class EDnDCurrency : uint8
{
	COPPER				UMETA(DisplayName = "Copper"),
	SILVER				UMETA(DisplayName = "Silver"),
	ELECTRUM			UMETA(DisplayName = "Electrum"),
	GOLD				UMETA(DisplayName = "Gold"),
	PLATINUM			UMETA(DisplayName = "Platinum"),
	CURRENCY_COUNT		UMETA(DisplayName = "None")
};

USTRUCT(BlueprintType)
struct CHARACTERDIARY_API FDnDCurrency
{
	GENERATED_BODY()
public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Currency")
	TMap<EBaseCurrency, int32>	Values;
};
