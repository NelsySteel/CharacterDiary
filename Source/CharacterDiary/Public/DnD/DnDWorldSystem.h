// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "IWorldSystem.h"
#include "DnDWorldSystem.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable, ClassGroup = "DnD", meta = (DisplayName = "DnD Inventory System"))
class CHARACTERDIARY_API UDnDWorldSystem : public UIWorldSystem
{
	GENERATED_BODY()
public:
	UDnDWorldSystem();
};
