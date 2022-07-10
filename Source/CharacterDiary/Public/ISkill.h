// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ISkill.generated.h"

class USkillsSystemComponent;
/**
 * 
 */
UCLASS(ClassGroup = "Skills", Blueprintable, BlueprintType)
class CHARACTERDIARY_API UISkill : public UObject
{
	GENERATED_BODY()
	friend USkillsSystemComponent;
public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Data")
	int32		GetModifier();

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	FString		Name;

	UPROPERTY(EditInstanceOnly, Category = "System")
	USkillsSystemComponent* SkillSystem;

	UPROPERTY(BlueprintReadOnly)
	int32		Key;

protected:
	UISkill() {}
	~UISkill();

	int			m_modifier;
};
