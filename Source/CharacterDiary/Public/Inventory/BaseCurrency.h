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

UCLASS(BlueprintType, Blueprintable, meta=(DisplayName = "Base Currency"))
class CHARACTERDIARY_API UBaseCurrency:public UObject
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, Category = "Initialization")
	void AddMoneyStruct(UBaseCurrency currency);

	UFUNCTION(BlueprintCallable, Category = "Initialization")
	void AddMoney(EBaseCurrency currency, int32 value);

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Currency")
	TMap<EBaseCurrency, int32>	Values;
};
