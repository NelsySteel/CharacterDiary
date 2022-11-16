// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/UserDefinedStruct.h"
#include "BaseCurrency.generated.h"

/**
 * 
 */
//

UENUM(Blueprintable, BlueprintType)
enum class EBaseCurrency : uint8
{
	COPPER				UMETA(DisplayName = "Copper"),
	SILVER				UMETA(DisplayName = "Silver"),
	GOLD				UMETA(DisplayName = "Gold"),
	CURRENCY_COUNT		UMETA(DisplayName = "None")
};

USTRUCT(BlueprintType, Blueprintable, meta=(DisplayName = "Base Currency"))
struct CHARACTERDIARY_API FBaseCurrency
{
	GENERATED_BODY()
public:
	FBaseCurrency();
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Currency")
	TMap<EBaseCurrency, int32>	Values;
};
