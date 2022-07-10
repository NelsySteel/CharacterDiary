// Fill out your copyright notice in the Description page of Project Settings.


#include "DnD/DnDGameSystem.h"

#include "DnD/DNDSkillsSystemComponent.h"

UDnDGameSystem::UDnDGameSystem()
{
	SkillSystemClass = UDNDSkillsSystemComponent::StaticClass();
}
