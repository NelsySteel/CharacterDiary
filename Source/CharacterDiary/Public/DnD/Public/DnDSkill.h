// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ISkill.h"
#include "IAbility.h"
#include "DnDSkill.generated.h"

/**
 * 
 */
UCLASS()
class CHARACTERDIARY_API UDnDSkill : public UISkill
{
	GENERATED_BODY()
public:
	UDnDSkill(int key, FString name, UIAbility* ability, bool proficiency);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Data")
	UIAbility* GetAbility();
	
	virtual int GetModifier_Implementation() override;
protected:
	UDnDSkill() : UISkill() {}

	UPROPERTY()
	UIAbility*	m_correspondingAbility;

	bool		m_isProficient;

};
