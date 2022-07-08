// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ISkill.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = "Skills", Blueprintable, BlueprintType)
class CHARACTERDIARY_API UISkill : public UObject
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Data")
	int	GetKey();
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Data")
	FString GetName();
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Data")
	int		GetModifier();


protected:
	UISkill() {}
	UISkill(int key, FString name, int modifier) : m_key(key), m_name(name), m_modifier(modifier) {}
	~UISkill();
	
	
	int			m_key;
	FString		m_name;
	int			m_modifier;
};
