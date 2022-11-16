// Fill out your copyright notice in the Description page of Project Settings.


#include "DnD/DnDWorldSystem.h"

#include "Inventory/DnD/DnDInventorySystemComponent.h"
#include "Skills/DnD/DNDSkillsSystemComponent.h"

UDnDWorldSystem::UDnDWorldSystem()
{
	SkillSystemClass = UDNDSkillsSystemComponent::StaticClass();
	InventorySystemClass = UDnDInventorySystemComponent::StaticClass();
}
