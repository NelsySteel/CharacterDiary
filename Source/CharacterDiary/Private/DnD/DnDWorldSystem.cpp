// Fill out your copyright notice in the Description page of Project Settings.


#include "DnD/DnDWorldSystem.h"

#include "DnD/DNDSkillsSystemComponent.h"

UDnDWorldSystem::UDnDWorldSystem()
{
	SkillSystemClass = UDNDSkillsSystemComponent::StaticClass();
}
