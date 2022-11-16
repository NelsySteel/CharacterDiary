// Fill out your copyright notice in the Description page of Project Settings.


#include "Inventory/DnD/DnDInventorySystemComponent.h"

#include "Inventory/DnD/DnDInventoryLogicBaseInfo.h"

TMap<FString, TSubclassOf<UIInventoryComponentLogic>> UDnDInventorySystemComponent::ComponentsMap = UDnDInventorySystemComponent::InitComponentsMap();



// static function
TMap<FString, TSubclassOf<UIInventoryComponentLogic>> UDnDInventorySystemComponent::InitComponentsMap()
{
	TMap<FString, TSubclassOf<UIInventoryComponentLogic>> result;

	result.Add("BaseInfo", UDnDInventoryLogicBaseInfo::StaticClass());

	return result;
}

UIInventoryComponentLogic* UDnDInventorySystemComponent::CreateLogicFromName(const FString& name)
{
	if (TSubclassOf<UIInventoryComponentLogic>* logicClassPtr = ComponentsMap.Find(name))
	{
		TSubclassOf<UIInventoryComponentLogic> logicClass = *logicClassPtr;
		UIInventoryComponentLogic* logic = NewObject<UIInventoryComponentLogic>(this, logicClass);
		return logic;
	}
	return nullptr;
}


void UDnDInventorySystemComponent::AddMoneyStruct(FDnDCurrency currency)
{
	for (auto item : currency.Values )
	{
		Wallet.Values[item.Key] += item.Value;
	}
}

void UDnDInventorySystemComponent::AddMoney(EDnDCurrency Currency, int32 Value)
{
	Wallet.Values[Currency] += Value;
}

UDnDInventorySystemComponent::UDnDInventorySystemComponent()
{

	
}
