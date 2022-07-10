// Fill out your copyright notice in the Description page of Project Settings.


#include "Skills/ISkill.h"


UISkill::~UISkill()
{
}

int32  UISkill::GetModifier_Implementation()
{
	return m_modifier;
}