// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Inventory/BaseCurrency.h"
#include "InventorySystemComponent.generated.h"


class UIInventoryComponentLogic;
enum class EDnDCurrency : uint8;
class UCurrency;
class UIInventoryObject;
UCLASS( ClassGroup=(DnD), meta=(BlueprintSpawnableComponent) )
class CHARACTERDIARY_API UInventorySystemComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventorySystemComponent();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Initialization")
	void Initialize();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Items")
		TArray<UIInventoryObject*>	Items;

	virtual UIInventoryComponentLogic* CreateLogicFromName(const FString& name);
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	virtual void LoadDefaultItemsFromXML(const FString& fileName);

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


};
