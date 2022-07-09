// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SkillsSystemComponent.h"
#include "Public/DnDSkill.h"
#include "DNDSkillsSystemComponent.generated.h"

class UISkill;
/**
 * 
 */

UENUM(Blueprintable, BlueprintType)
enum Skill
{
	ACROBATICS				UMETA(DisplayName = "Acrobatics"),
	ANIMAL_HANDLING			UMETA(DisplayName = "Animal Handling"),
	ARCANA					UMETA(DisplayName = "Arcana"),
	ATLETICS				UMETA(DisplayName = "Athletics"),
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
	SKILL_COUNT				UMETA(DisplayName = "None")
};

UENUM(Blueprintable, BlueprintType)
enum Ability
{
	STRENGTH			UMETA(DisplayName = "Strength"),
	DEXTERITY			UMETA(DisplayName = "Dexterity"),
	CONSTITUTION		UMETA(DisplayName = "Constitution"),
	WISDOM				UMETA(DisplayName = "Wisdom"),
	INTELLIGENCE		UMETA(DisplayName = "Intelligence"),
	CHARISMA			UMETA(DisplayName = "Charisma"),
	ABILITY_COUNT		UMETA(DisplayName = "None")
};



UCLASS(ClassGroup = "DnD", meta = (BlueprintSpawnableComponent))
class CHARACTERDIARY_API UDNDSkillsSystemComponent : public USkillsSystemComponent
{
	GENERATED_BODY()
	friend UDnD_Skill;
public:
	UDNDSkillsSystemComponent() : USkillsSystemComponent() {}

	virtual UISkill*
	CreateBaseSkill_Implementation(int key, const FString& name, int modifier = 0) override;
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Skills")
	UDnD_Skill* CreateSkill(int Key, const FString& Name, int Modifier, int AbilityEnum, bool IsProficient);
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Skills")
	UIAbility* CreateAbilityObject(int AbilityEnum);

	virtual void Initialize_Implementation(UIGameSystem* system) override;
protected:

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Initialization")
	void PostInitialize();
public:
	UFUNCTION(BlueprintCallable, Category = "Skills")
	TArray<UISkill*> GetAllSkills();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Skills")
	int ProficiencyValue = 2;
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

	UPROPERTY()
	TMap<int, UISkill*>			m_skills;

	UPROPERTY()
	TMap<int, UIAbility*>		m_abilities;

};