// Fill out your copyright notice in the Description page of Project Settings.


#include "Skills/DnD/DnDSkill.h"
#include "Skills/DnD/DNDSkillsSystemComponent.h"

void UDnD_Skill::UpdateProficiency_Implementation(bool newValue)
{
	IsProficient = newValue;

	// Event to recount all values in UI
}

int UDnD_Skill::GetModifier_Implementation()
{
	const int skillProficiencyValue = Cast<UDNDSkillsSystemComponent>(SkillSystem)->ProficiencyValue;

	int modifier = 0;
	if (CorrespondingAbility)
		modifier = (CorrespondingAbility->GetModifier() - 10) / 2;
	
	if (IsProficient) modifier += skillProficiencyValue;
	return modifier;
}

TMap<ESkillImprovementOrigin, int32> UDnD_Skill::GetModifier_FullInfo_Implementation()
{
	TMap<ESkillImprovementOrigin, int32> result;
	if (CorrespondingAbility)
	{
		result.Add(ESkillImprovementOrigin::ABILITY, (CorrespondingAbility->GetModifier() - 10) / 2);
	}
	if (IsProficient)
	{
		const int skillProficiencyValue = Cast<UDNDSkillsSystemComponent>(SkillSystem)->ProficiencyValue;
		result.Add(ESkillImprovementOrigin::PROFICIENCY, skillProficiencyValue);
	}
	return result;
}
