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
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Data")
	int GetModifier();
protected:
	UIAbility();
	~UIAbility();


	bool m_modifier;
};
