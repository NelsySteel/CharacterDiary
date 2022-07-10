// Fill out your copyright notice in the Description page of Project Settings.


#include "DnD/DNDSkillsSystemComponent.h"

#include "IGameSystem.h"
#include "ISkill.h"
#include "DnD/DnDGameSystem.h"
#include "DnD/Public/DnDSkill.h"
#include "IAbility.h"

UDNDSkillsSystemComponent::UDNDSkillsSystemComponent() : USkillsSystemComponent()
{
	SkillCategories.Add(ESkill::ACROBATICS, EAbility::DEXTERITY);
	SkillCategories.Add(ESkill::ANIMAL_HANDLING, EAbility::WISDOM);
	SkillCategories.Add(ESkill::ARCANA, EAbility::INTELLIGENCE);
	SkillCategories.Add(ESkill::ATHLETICS, EAbility::STRENGTH);
	SkillCategories.Add(ESkill::DECEPTION, EAbility::CHARISMA);
	SkillCategories.Add(ESkill::HISTORY, EAbility::INTELLIGENCE);
	SkillCategories.Add(ESkill::INSIGHT, EAbility::WISDOM);
	SkillCategories.Add(ESkill::INTIMIDATION, EAbility::CHARISMA);
	SkillCategories.Add(ESkill::INVESTIGATION, EAbility::INTELLIGENCE);
	SkillCategories.Add(ESkill::MEDICINE, EAbility::WISDOM);
	SkillCategories.Add(ESkill::NATURE, EAbility::INTELLIGENCE);
	SkillCategories.Add(ESkill::PERCEPTION, EAbility::WISDOM);
	SkillCategories.Add(ESkill::PERFORMANCE, EAbility::CHARISMA);
	SkillCategories.Add(ESkill::PERSUASION, EAbility::CHARISMA);
	SkillCategories.Add(ESkill::RELIGION, EAbility::INTELLIGENCE);
	SkillCategories.Add(ESkill::SLEIGHT_OF_HAND, EAbility::DEXTERITY);
	SkillCategories.Add(ESkill::STEALTH, EAbility::DEXTERITY);
	SkillCategories.Add(ESkill::SURVIVAL, EAbility::WISDOM);

}

UISkill* UDNDSkillsSystemComponent::CreateBaseSkill_Implementation(int key, const FString& Name, int Modifier)
{
	auto skill = NewObject<UDnD_Skill>(this, UDnD_Skill::StaticClass(), FName(Name));
	skill->Key = key;
	skill->SkillSystem = this;
	skill->Name = Name;
	skill->m_modifier = Modifier;
	skill->CorrespondingAbility = nullptr;
	skill->IsProficient = false;
	return skill;
}

UDnD_Skill* UDNDSkillsSystemComponent::CreateSkill_Implementation(int Key, const FString& Name, int Modifier, EAbility AbilityEnum, bool IsProficient)
{
	auto skill = NewObject<UDnD_Skill>(this, UDnD_Skill::StaticClass(), FName(Name));
	skill->Key = Key;
	skill->SkillSystem = this;
	skill->Name = Name;
	skill->m_modifier = Modifier;
	skill->CorrespondingAbility = Abilities[AbilityEnum];
	skill->IsProficient = IsProficient;
	return skill;
}


UIAbility* UDNDSkillsSystemComponent::CreateAbilityObject_Implementation(EAbility AbilityEnum)
{
	int abilityIndex = static_cast<uint8>(AbilityEnum);
	auto AbilityObject = NewObject<UIAbility>(this, UIAbility::StaticClass(), FName(AbilityNames[abilityIndex]));
	AbilityObject->Name = AbilityNames[abilityIndex];
	AbilityObject->Modifier = 10;
	return AbilityObject;
}

void UDNDSkillsSystemComponent::Initialize_Implementation(UIGameSystem* system)
{
	Super::Initialize_Implementation(system);
	UDnDGameSystem* worldSystem = Cast<UDnDGameSystem>(WorldSystem);
	if (!worldSystem)
	{
		//Wrong system!
		return;
	}
	PostInitialize();

}

void UDNDSkillsSystemComponent::PostInitialize_Implementation()
{
	if (WorldSystem)
	{
		for (int i = 0; i <= static_cast<uint8>(EAbility::ABILITY_COUNT); i++)
		{
			EAbility abilityEnum = static_cast<EAbility>(i);
			Abilities.Add(abilityEnum, CreateAbilityObject(abilityEnum));
		}

		for (int i = 0; i<= static_cast<uint8>(ESkill::SKILL_COUNT); i++)
		{
			FString skillName = SkillNames[i];
			ESkill skillEnum = static_cast<ESkill>(i);
			Skills.Add(skillEnum, CreateSkill(i, skillName, 0, skillEnum != ESkill::SKILL_COUNT ? SkillCategories[skillEnum] : EAbility::ABILITY_COUNT, false));
		}
	}
}


TArray<UISkill*> UDNDSkillsSystemComponent::GetAllSkills()
{

	TArray<UISkill*> result;
	Skills.GenerateValueArray(result);
	return result;
}
