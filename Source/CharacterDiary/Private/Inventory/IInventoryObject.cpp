// Fill out your copyright notice in the Description page of Project Settings.


#include "Inventory/IInventoryObject.h"

#include "Inventory/IInventoryItemInfoDataAsset.h"

void UIInventoryObject::OnConstruct_Implementation(
	TSubclassOf<UIInventoryComponentLogic> subclass)
{

}

UIInventoryObject::UIInventoryObject()
	:UObject()
{
	for (auto&& dataComponent : Components)
	{
		
	}
}

UIInventoryComponentLogic* UIInventoryObject::GetComponentOfClass(TSubclassOf<UIInventoryComponentLogic> subclass)
{
	return GetComponentOfClass<UIInventoryComponentLogic>(subclass);
}

bool UIInventoryObject::CreateAndAddLogic(UIInventoryItemInfoDataAsset* data)
{
	TSubclassOf<UIInventoryComponentLogic> LogicClass = data->LogicClass;
	UIInventoryComponentLogic* existingLogic = GetComponentOfClass(LogicClass);
	if (existingLogic)
	{
		//Error?
	}
	UIInventoryComponentLogic* newLogic = NewObject<UIInventoryComponentLogic>(this, LogicClass, FName(data->LogicName));
	newLogic->data = data;
	ComponentsLogics.Add(newLogic);
	return true;
}
