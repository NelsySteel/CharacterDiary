// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Types.h"
#include "GameFramework/Actor.h"
#include "ICharacter.generated.h"

class USkillsSystemComponent;
class UIGameSystem;
UCLASS(ClassGroup = "Game", BlueprintType, Blueprintable)
class CHARACTERDIARY_API AICharacter : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AICharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "System")
	TEnumAsByte<System>			WorldSystemEnum;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "System")
	UIGameSystem*	WorldSystem;

	// UPROPERTY(BlueprintReadOnly, VisibleAnywhere, AdvancedDisplay, Category="Components")
	// USkillsSystemComponent* SkillsSystem;
private:
	template<class TClass>
	TClass* AddComponent(FName name);
};

template <class TClass>
TClass* AICharacter::AddComponent(FName name)
{
	UActorComponent* NewComp = NewObject<UActorComponent>(this, TClass::StaticClass(), name);
	TClass* comp = Cast<TClass>(NewComp);
	comp->RegisterComponent();
	AddInstanceComponent(comp);
	return comp;
}
