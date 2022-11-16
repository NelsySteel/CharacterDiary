// Fill out your copyright notice in the Description page of Project Settings.


#include "Inventory/IInventoryObject.h"

UIInventoryObject::UIInventoryObject()
	:UObject()
{
}

UIInventoryComponentLogic* UIInventoryObject::GetComponentOfClass(TSubclassOf<UIInventoryComponentLogic> subclass)
{
	return GetComponentOfClass<UIInventoryComponentLogic>(subclass);
}

UIInventoryComponentLogic* UIInventoryObject::CreateAndAddLogic(TSubclassOf<UIInventoryComponentLogic> logicClass, FName LogicName)
{
	UIInventoryComponentLogic* newLogic = NewObject<UIInventoryComponentLogic>(this, logicClass, LogicName);
	ComponentsLogics.Add(newLogic);
	return newLogic;
}

void UIInventoryObject::AddLogic(UIInventoryComponentLogic* logic)
{
	ComponentsLogics.Add(logic);
}
