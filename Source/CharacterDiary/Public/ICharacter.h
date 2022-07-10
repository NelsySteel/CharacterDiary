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
	System			WorldSystemEnum;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "System")
	UIGameSystem*	WorldSystem;

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "Skills")
	void OnSkillSystemReady();

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category="Components")
	USkillsSystemComponent* SkillsSystem;
private:
	template<class TClass>
	TClass* AddComponent(FName name);
};

template <class TClass>
TClass* AICharacter::AddComponent(FName name)
{
	UActorComponent* NewComp = NewObject<TClass>(this, WorldSystem->SkillSystemClass, name);
	NewComp->RegisterComponent();
	AddInstanceComponent(NewComp);
	return Cast<TClass>(NewComp);;
}
