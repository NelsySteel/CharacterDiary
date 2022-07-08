// Fill out your copyright notice in the Description page of Project Settings.


#include "ISkill.h"


UISkill::~UISkill()
{
}


int UISkill::GetKey_Implementation()
{
	return m_key;
}

FString UISkill::GetName_Implementation()
{
	return m_name;
}

int UISkill::GetModifier_Implementation()
{
	return m_modifier;
}