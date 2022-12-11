// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "IWorldSystem.generated.h"


UENUM(Blueprintable, BlueprintType)
enum class System : uint8
{
	DND			UMETA(DisplayName = "DnD"),
	Systems_COUNT		UMETA(DisplayName = "None")
};


class UInventorySystemComponent;
class USkillsSystemComponent;
class UISkill;
/**
 *
 */
UCLASS(ClassGroup = "GameSystem", Blueprintable, BlueprintType)
class CHARACTERDIARY_API UIWorldSystem: public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Components")
	TSubclassOf<USkillsSystemComponent> SkillSystemClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Components")
	TSubclassOf<UInventorySystemComponent> InventorySystemClass;


protected:
	UIWorldSystem();
	~UIWorldSystem();
};
