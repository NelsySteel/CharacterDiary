// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/SkillsSystemComponent.h"

#include "Skills/ISkill.h"


// Sets default values for this component's properties
USkillsSystemComponent::USkillsSystemComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void USkillsSystemComponent::Initialize_Implementation()
{
}


// Called when the game starts
void USkillsSystemComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void USkillsSystemComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

