// Fill out your copyright notice in the Description page of Project Settings.


#include "DnD/DNDSkillsSystemComponent.h"

#include "IGameSystem.h"
#include "ISkill.h"
#include "DnD/DnDGameSystem.h"
#include "DnD/Public/DnDSkill.h"
#include "IAbility.h"

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
	skill->CorrespondingAbility = m_abilities[AbilityEnum];
	skill->IsProficient = IsProficient;
	return skill;
}


UIAbility* UDNDSkillsSystemComponent::CreateAbilityObject_Implementation(int AbilityEnum)
{
	auto AbilityObject = NewObject<UIAbility>(this, UIAbility::StaticClass(), FName(AbilityNames[AbilityEnum]));
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
			m_abilities.Add(i, CreateAbilityObject(i));
		}

		for (int i = 0; i<= Skill::SKILL_COUNT; i++)
		{
			FString skillName = SkillNames[i];
			m_skills.Add(i, CreateSkill(i, skillName, 0, Ability::ABILITY_COUNT, false));
		}

		
	}
}


TArray<UISkill*> UDNDSkillsSystemComponent::GetAllSkills()
{

	TArray<UISkill*> result;
	m_skills.GenerateValueArray(result);
	return result;
}
