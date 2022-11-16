// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "IInventoryComponentLogic.h"
#include "UObject/NoExportTypes.h"
#include "IInventoryObject.generated.h"
class UIInventoryItemInfoObject;
/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class CHARACTERDIARY_API UIInventoryObject : public UObject
{
	GENERATED_BODY()

public:
	UIInventoryObject();

	UFUNCTION(BlueprintCallable, Category="Components")
	UIInventoryComponentLogic* GetComponentOfClass(TSubclassOf<UIInventoryComponentLogic> subclass);

	UFUNCTION(BlueprintCallable, BlueprintCallable, Category = "Components")
	UIInventoryComponentLogic* CreateAndAddLogic(TSubclassOf<UIInventoryComponentLogic> logicClass, FName LogicName);


	UFUNCTION(BlueprintCallable, BlueprintCallable, Category = "Components")
	void AddLogic(UIInventoryComponentLogic* logic);

	UPROPERTY(BlueprintReadOnly, Category = "Components")
	TArray<UIInventoryComponentLogic*>	ComponentsLogics;
public:
	template <class TComponentClass>
	TComponentClass* GetComponentOfClass(TSubclassOf<UIInventoryComponentLogic> logicClass = TComponentClass::StaticClass());

	
};

template <class TComponentClass>
TComponentClass* UIInventoryObject::GetComponentOfClass(TSubclassOf<UIInventoryComponentLogic> logicClass)
{
	UIInventoryComponentLogic** FoundComponentPtr = ComponentsLogics.FindByPredicate([&](const UIInventoryComponentLogic* Object)
	{
		return Cast<TComponentClass>(Object) != nullptr && Object->GetClass() == logicClass;
	}
	);
	if (UIInventoryComponentLogic* FoundComponent = *FoundComponentPtr)
	{
		return Cast<TComponentClass>(FoundComponent);
	}
	return nullptr;
}
