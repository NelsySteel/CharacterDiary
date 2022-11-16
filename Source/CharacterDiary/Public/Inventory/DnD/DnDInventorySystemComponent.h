// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/InventorySystemComponent.h"
#include "Inventory/DnD/DnDCurrency.h"
#include "DnDInventorySystemComponent.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (DnD), meta = (BlueprintSpawnableComponent, DisplayName = "DND Inventory System"))
class CHARACTERDIARY_API UDnDInventorySystemComponent : public UInventorySystemComponent
{
	GENERATED_BODY()
public:

	UDnDInventorySystemComponent();

	UFUNCTION(BlueprintCallable, Category = "Initialization")
	void AddMoneyStruct(FDnDCurrency currency);
	
	UFUNCTION(BlueprintCallable, Category = "Initialization")
	void AddMoney(EDnDCurrency currency, int32 value);

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Money")
	FDnDCurrency					Wallet;

	virtual UIInventoryComponentLogic* CreateLogicFromName(const FString& name) override;
private:
	static TMap<FString, TSubclassOf<UIInventoryComponentLogic>> InitComponentsMap();
	static TMap<FString, TSubclassOf<UIInventoryComponentLogic>> ComponentsMap;
};
