// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */

UENUM(Blueprintable, BlueprintType)
enum System
{
	DND			UMETA(DisplayName = "DnD"),
	Systems_COUNT		UMETA(DisplayName = "None")
};

class CHARACTERDIARY_API Types
{
public:
	Types();
	~Types();
};
