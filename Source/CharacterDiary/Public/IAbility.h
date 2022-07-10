// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "IAbility.generated.h"

/**
 *
 */
UCLASS(ClassGroup = "Skills", Blueprintable, BlueprintType)
class CHARACTERDIARY_API UIAbility: public UObject
{
	GENERATED_BODY()

public:
	UIAbility();
	~UIAbility();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Data")
		int32  GetModifier();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int32  Modifier;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	FString		Name;
};
