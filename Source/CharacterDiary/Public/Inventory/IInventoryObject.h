// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "IInventoryComponentLogic.h"
#include "UObject/NoExportTypes.h"
#include "IInventoryObject.generated.h"
class UIInventoryItemInfoDataAsset;
/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class CHARACTERDIARY_API UIInventoryObject : public UObject
{
	GENERATED_BODY()

public:
	UIInventoryObject();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Components")
	void OnConstruct(TSubclassOf<UIInventoryComponentLogic> subclass);

	UFUNCTION(BlueprintCallable, Category="Components")
	UIInventoryComponentLogic* GetComponentOfClass(TSubclassOf<UIInventoryComponentLogic> subclass);
	

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Components")
	TArray<UIInventoryItemInfoDataAsset*>	Components;

	UPROPERTY(BlueprintReadOnly, Category = "Components")
	TArray<UIInventoryComponentLogic*>	ComponentsLogics;
public:
	template <class TComponentClass>
	TComponentClass* GetComponentOfClass(TSubclassOf<UIInventoryComponentLogic> subclass = TComponentClass::StaticClass());
private:
	bool CreateAndAddLogic(UIInventoryItemInfoDataAsset*  data);
	
};

template <class TComponentClass>
TComponentClass* UIInventoryObject::GetComponentOfClass(TSubclassOf<UIInventoryComponentLogic> subclass)
{
	UIInventoryComponentLogic** FoundComponentPtr = ComponentsLogics.FindByPredicate([&](const UIInventoryComponentLogic* Object)
	{
		return Cast<TComponentClass>(Object) != nullptr && Object->GetClass() == subclass;
	}
	);
	UIInventoryComponentLogic* FoundComponent = *FoundComponentPtr;
	if (FoundComponent)
	{
		return Cast<TComponentClass>(FoundComponent);
	}
	return nullptr;
}
