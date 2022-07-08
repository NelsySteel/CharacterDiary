// Fill out your copyright notice in the Description page of Project Settings.


#include "DnD/Public/DnDSkill.h"

UDnDSkill::UDnDSkill(int key, FString name, UIAbility* ability, bool proficiency) : UISkill(key, name, 0)
{
	
}

int UDnDSkill::GetModifier_Implementation()
{
	auto modifier = (GetAbility()->GetModifier() - 10) / 2;
	return modifier;
}


UIAbility* UDnDSkill::GetAbility_Implementation()
{
	return m_correspondingAbility;
}
