// Fill out your copyright notice in the Description page of Project Settings.


#include "DnD/DNDSkillsSystemComponent.h"

#include "IGameSystem.h"
#include "ISkill.h"
#include "DnD/DnDGameSystem.h"
#include "DnD/Public/DnDSkill.h"
#include "IAbility.h"

UDNDSkillsSystemComponent::UDNDSkillsSystemComponent() : USkillsSystemComponent()
{
	SkillCategories.Add(Skill::ACROBATICS, Ability::DEXTERITY);
	SkillCategories.Add(Skill::ANIMAL_HANDLING, Ability::WISDOM);
	SkillCategories.Add(Skill::ARCANA, Ability::INTELLIGENCE);
	SkillCategories.Add(Skill::ATHLETICS, Ability::STRENGTH);
	SkillCategories.Add(Skill::DECEPTION, Ability::CHARISMA);
	SkillCategories.Add(Skill::HISTORY, Ability::INTELLIGENCE);
	SkillCategories.Add(Skill::INSIGHT, Ability::WISDOM);
	SkillCategories.Add(Skill::INTIMIDATION, Ability::CHARISMA);
	SkillCategories.Add(Skill::INVESTIGATION, Ability::INTELLIGENCE);
	SkillCategories.Add(Skill::MEDICINE, Ability::WISDOM);
	SkillCategories.Add(Skill::NATURE, Ability::INTELLIGENCE);
	SkillCategories.Add(Skill::PERCEPTION, Ability::WISDOM);
	SkillCategories.Add(Skill::PERFORMANCE, Ability::CHARISMA);
	SkillCategories.Add(Skill::PERSUASION, Ability::CHARISMA);
	SkillCategories.Add(Skill::RELIGION, Ability::INTELLIGENCE);
	SkillCategories.Add(Skill::SLEIGHT_OF_HAND, Ability::DEXTERITY);
	SkillCategories.Add(Skill::STEALTH, Ability::DEXTERITY);
	SkillCategories.Add(Skill::SURVIVAL, Ability::WISDOM);

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

UDnD_Skill* UDNDSkillsSystemComponent::CreateSkill_Implementation(int Key, const FString& Name, int Modifier, int AbilityEnum, bool IsProficient)
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


UIAbility* UDNDSkillsSystemComponent::CreateAbilityObject_Implementation(int AbilityEnum)
{
	auto AbilityObject = NewObject<UIAbility>(this, UIAbility::StaticClass(), FName(AbilityNames[AbilityEnum]));
	AbilityObject->Name = AbilityNames[AbilityEnum];
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
		for (int i = 0; i <= Ability::ABILITY_COUNT; i++)
		{
			Abilities.Add(i, CreateAbilityObject(i));
		}

		for (int i = 0; i<= Skill::SKILL_COUNT; i++)
		{
			FString skillName = SkillNames[i];
			Skill skillEnum = static_cast<Skill>(i);
			Skills.Add(i, CreateSkill(i, skillName, 0, skillEnum!=Skill::SKILL_COUNT ? SkillCategories[skillEnum] : Ability::ABILITY_COUNT, false));
		}
	}
}


TArray<UISkill*> UDNDSkillsSystemComponent::GetAllSkills()
{

	TArray<UISkill*> result;
	Skills.GenerateValueArray(result);
	return result;
}
