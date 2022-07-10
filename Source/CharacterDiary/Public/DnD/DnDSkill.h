// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ISkill.h"
#include "IAbility.h"
#include "DnDSkill.generated.h"

class UDNDSkillsSystemComponent;
/**
 * 
 */
UCLASS()
class CHARACTERDIARY_API UDnD_Skill : public UISkill
{
	GENERATED_BODY()
	friend UDNDSkillsSystemComponent;
public:
	UDnD_Skill() : UISkill() {}

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Data")
	void UpdateProficiency(bool newValue);
	
	virtual int GetModifier_Implementation() override;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	UIAbility* CorrespondingAbility;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool		IsProficient;

protected:
};
