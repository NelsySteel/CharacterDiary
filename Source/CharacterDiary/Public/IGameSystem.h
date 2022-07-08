// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "IGameSystem.generated.h"

class UISkill;
/**
 *
 */
UCLASS(ClassGroup = "GameSystem", Blueprintable, BlueprintType)
class CHARACTERDIARY_API UIGameSystem: public UObject
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="Skills")
	TArray<UISkill*> CreateSkills();
protected:
	UIGameSystem();
	~UIGameSystem();
};
