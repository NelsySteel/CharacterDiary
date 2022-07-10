// Fill out your copyright notice in the Description page of Project Settings.


#include "ICharacter.h"

#include "Components/InventorySystemComponent.h"
#include "Skills/DnD/DNDSkillsSystemComponent.h"
#include "DnD/DnDWorldSystem.h"

// Sets default values
AICharacter::AICharacter()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AICharacter::BeginPlay()
{
	switch (WorldSystemEnum)
	{
	case System::DND: 
	{
		WorldSystem = NewObject<UDnDWorldSystem>();
		SkillsSystem = AddComponent<USkillsSystemComponent>("SkillSystem", WorldSystem->SkillSystemClass);
		SkillsSystem->Initialize();
		OnSkillSystemReady();

		InventorySystem = AddComponent<UInventorySystemComponent>("InventorySystem", WorldSystem->InventorySystemClass);
		InventorySystem->Initialize();
		break;
	}
	case System::Systems_COUNT: break;
	default: ;
	}
	Super::BeginPlay();
	
}

// Called every frame
void AICharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

