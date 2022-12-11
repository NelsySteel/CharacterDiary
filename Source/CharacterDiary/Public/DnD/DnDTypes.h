// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "DnDTypes.generated.h"



UENUM()
enum DiceType
{
	D4		UMETA(DisplayName = "d4"),
	D6		UMETA(DisplayName = "d6"),
	D8		UMETA(DisplayName = "d8"),
	D10		UMETA(DisplayName = "d10"),
	D12		UMETA(DisplayName = "d12"),
	D20		UMETA(DisplayName = "d20"),
	UNKNOWN		UMETA(DisplayName = "Unknown"),
};

UENUM()
enum DnDDamageType
{
	PIERCING		UMETA(DisplayName = "Piercing"),
	BLUGGEONING		UMETA(DisplayName = "Bludgeoning"),
	SLASHING		UMETA(DisplayName = "Slashing"),
	ACID			UMETA(DisplayName = "Acid"),
	COLD			UMETA(DisplayName = "Cold"),
	FIRE			UMETA(DisplayName = "Fire"),
	FORCE			UMETA(DisplayName = "Force"),
	LIGHTNING		UMETA(DisplayName = "Lightning"),
	NECROTIC		UMETA(DisplayName = "Necrotic"),
	POISON			UMETA(DisplayName = "Poison"),
	PSYCHIC			UMETA(DisplayName = "Psychic"),
	RADIANT			UMETA(DisplayName = "Radiant"),
	THUNDER			UMETA(DisplayName = "Thunder"),
	CUSTOM			UMETA(DisplayName = "Custom"),
};


UENUM()
enum DnDWeaponTraits
{
	TWO_HANDED		UMETA(DisplayName = "Two Handed"),
	RANGED			UMETA(DisplayName = "Ranged"),
	REACH			UMETA(DisplayName = "Reach"),
	NEEDS_AMMO		UMETA(DisplayName = "Ammunition"),
	RELOADING		UMETA(DisplayName = "Reloading"),
	LIGHT			UMETA(DisplayName = "Light"),
	THROWN			UMETA(DisplayName = "Thrown"),
	FINESSE			UMETA(DisplayName = "Finesse"),
	HEAVY			UMETA(DisplayName = "Heavy"),
	VERSATILE		UMETA(DisplayName = "Versatile"),
	IMPROVISED		UMETA(DisplayName = "Improvised"),
	SILVERED		UMETA(DisplayName = "Silvered"),
	SPECIAL			UMETA(DisplayName = "Special"),
	UNDEFINED		UMETA(DisplayName = "Undefined"),
};