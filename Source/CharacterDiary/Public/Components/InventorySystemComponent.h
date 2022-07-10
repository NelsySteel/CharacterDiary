// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Inventory/BaseCurrency.h"
#include "InventorySystemComponent.generated.h"


enum class EDnDCurrency : uint8;
class UCurrency;
class UIInventoryObject;
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CHARACTERDIARY_API UInventorySystemComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventorySystemComponent();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Initialization")
	void Initialize();

	


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Items")
	TArray<UIInventoryObject*>	Items;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Money")
	FBaseCurrency					Wallet;

};
