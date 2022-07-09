// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "IGameSystem.generated.h"

class USkillsSystemComponent;
class UISkill;
/**
 *
 */
UCLASS(ClassGroup = "GameSystem", Blueprintable, BlueprintType)
class CHARACTERDIARY_API UIGameSystem: public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Components")
	TSubclassOf<USkillsSystemComponent> SkillSystemClass;
protected:
	UIGameSystem();
	~UIGameSystem();
};
