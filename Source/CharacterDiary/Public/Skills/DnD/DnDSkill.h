// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Skills/ISkill.h"
#include "IAbility.h"
#include "DnDSkill.generated.h"

class UDNDSkillsSystemComponent;



UENUM(Blueprintable, BlueprintType)
enum class ESkillImprovementOrigin : uint8
{
	RACE				UMETA(DisplayName = "From Race"),
	CLASS				UMETA(DisplayName = "From Skill"),
	ABILITY				UMETA(DisplayName = "Ability"),
	PROFICIENCY			UMETA(DisplayName = "Proficiency"),
	ITEMS				UMETA(DisplayName = "Item"),
	PLATINUM			UMETA(DisplayName = "Platinum"),
	COUNT				UMETA(DisplayName = "None")
};


/**
 * 
 */
UCLASS(BlueprintType, Blueprintable, ClassGroup = "DnD", meta = (DisplayName = "DND Skill"))
class CHARACTERDIARY_API UDnD_Skill : public UISkill
{
	GENERATED_BODY()
	friend UDNDSkillsSystemComponent;
public:
	UDnD_Skill() : UISkill() {}

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Data")
	void UpdateProficiency(bool newValue);
	
	virtual int GetModifier_Implementation() override;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Data")
	TMap<ESkillImprovementOrigin, int32> GetModifier_FullInfo();

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	UIAbility* CorrespondingAbility;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool		IsProficient;

protected:
};
