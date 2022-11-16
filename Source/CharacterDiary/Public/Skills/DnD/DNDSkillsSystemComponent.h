// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SkillsSystemComponent.h"
#include "DnDSkill.h"
#include "DNDSkillsSystemComponent.generated.h"

class UISkill;
/**
 * 
 */

UENUM(Blueprintable, BlueprintType)
enum class ESkill : uint8
{
	ACROBATICS				UMETA(DisplayName = "Acrobatics"),
	ANIMAL_HANDLING			UMETA(DisplayName = "Animal Handling"),
	ARCANA					UMETA(DisplayName = "Arcana"),
	ATHLETICS				UMETA(DisplayName = "Athletics"),
	DECEPTION				UMETA(DisplayName = "Deception"),
	HISTORY					UMETA(DisplayName = "History"),
	INSIGHT					UMETA(DisplayName = "Insight"),
	INTIMIDATION			UMETA(DisplayName = "Intimidation"),
	INVESTIGATION			UMETA(DisplayName = "Investigation"),
	MEDICINE				UMETA(DisplayName = "Medicine"),
	NATURE					UMETA(DisplayName = "Nature"),
	PERCEPTION				UMETA(DisplayName = "Perception"),
	PERFORMANCE				UMETA(DisplayName = "Performance"),
	PERSUASION				UMETA(DisplayName = "Persuasion"),
	RELIGION				UMETA(DisplayName = "Religion"),
	SLEIGHT_OF_HAND			UMETA(DisplayName = "Sleight of Hand"),
	STEALTH					UMETA(DisplayName = "Stealth"),
	SURVIVAL				UMETA(DisplayName = "Survival"),
	COUNT					UMETA(DisplayName = "None")
};

UENUM(Blueprintable, BlueprintType)
enum class EAbility : uint8
{
	STRENGTH			UMETA(DisplayName = "Strength"),
	DEXTERITY			UMETA(DisplayName = "Dexterity"),
	CONSTITUTION		UMETA(DisplayName = "Constitution"),
	WISDOM				UMETA(DisplayName = "Wisdom"),
	INTELLIGENCE		UMETA(DisplayName = "Intelligence"),
	CHARISMA			UMETA(DisplayName = "Charisma"),
	COUNT				UMETA(DisplayName = "None")
};



UCLASS(ClassGroup = "DnD", meta = (BlueprintSpawnableComponent, DisplayName = "DND Skills System"))
class CHARACTERDIARY_API UDNDSkillsSystemComponent : public USkillsSystemComponent
{
	GENERATED_BODY()
	friend UDnD_Skill;
public:
	UDNDSkillsSystemComponent();
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Skills")
	UDnD_Skill* CreateSkill(int Key, const FString& Name, int Modifier, EAbility AbilityEnum, bool IsProficient);
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Skills")
	UIAbility* CreateAbilityObject(EAbility AbilityEnum);

	virtual void Initialize_Implementation() override;

public:
	UFUNCTION(BlueprintCallable, Category = "Skills")
	TArray<UISkill*> GetAllSkills();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Skills")
	int32  ProficiencyValue = 2;

	UPROPERTY(BlueprintReadOnly, Category="Skills")
		TMap<ESkill, UISkill*>			Skills;

	UPROPERTY(BlueprintReadOnly, Category = "Skills")
		TMap<EAbility, UIAbility*>		Abilities;
private:
	TArray<FString> SkillNames = {
		"Acrobatics",
		"Animal Handling",
		"Arcana",
		"Athletics",
		"Deception",
		"History",
		"Insight",
		"Intimidation",
		"Investigation",
		"Medicine",
		"Nature",
		"Perception",
		"Performance",
		"Persuasion",
		"Religion",
		"Sleight of Hand",
		"Stealth",
		"Survival",
		"None"
	};

	TArray<FString> AbilityNames = {
		"STRENGTH",
		"DEXTERITY",
		"CONSTITUTION",
		"WISDOM",
		"INTELLIGENCE",
		"CHARISMA",
		"None"
	};

	TMap<ESkill, EAbility> SkillCategories;


};
