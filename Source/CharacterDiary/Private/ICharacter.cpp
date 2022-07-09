// Fill out your copyright notice in the Description page of Project Settings.


#include "ICharacter.h"
#include "DnD/DNDSkillsSystemComponent.h"
#include "DnD/DnDGameSystem.h"

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
	case DND: 
	{
		WorldSystem = NewObject<UDnDGameSystem>();
		SkillsSystem = AddComponent<UDNDSkillsSystemComponent>("SkillSystem");
		SkillsSystem->Initialize(WorldSystem);
		OnSkillSystemReady();
		break;
	}
	case Systems_COUNT: break;
	default: ;
	}
	Super::BeginPlay();
	
}

// Called every frame
void AICharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

