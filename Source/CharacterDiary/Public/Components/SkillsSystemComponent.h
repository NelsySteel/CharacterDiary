// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SkillsSystemComponent.generated.h"


class UISkill;
class UIGameSystem;
UCLASS( )
class CHARACTERDIARY_API USkillsSystemComponent : public UActorComponent
{
	GENERATED_BODY()
public:	
	

	// Sets default values for this component's properties
	USkillsSystemComponent();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Data")
	UISkill* CreateBaseSkill(int key, const FString& name, int modifier = 0);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Initialization")
	void Initialize(UIGameSystem* system);

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "System")
	UIGameSystem* WorldSystem;
};
