// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../IInventoryComponentLogic.h"
#include "DnD/DnDTypes.h"
#include "DnDInventoryLogicDamage.generated.h"

/**
 * 
 */


USTRUCT(BlueprintType, Blueprintable)
struct FDamageOption
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ItemDamageData")
		TEnumAsByte<DnDDamageType>	DamageType;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ItemDamageData")
		uint8 DamageDiceCount;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ItemDamageData")
		TEnumAsByte<DiceType> DamageDice;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ItemDamageData")
		FString AttackDesc;
};

UCLASS(BlueprintType, Blueprintable)
class CHARACTERDIARY_API UDnDInventoryLogicDamage : public UIInventoryComponentLogic
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ItemDamageData")
		TArray<FDamageOption> DamageOptions;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ItemDamageData")
		TSet<TEnumAsByte<DnDWeaponTraits>> WeaponTraits;

protected:
	virtual bool LoadFromXML(FXmlNode* rootNode) override;
private:
	static TMap<FString, TEnumAsByte<DnDWeaponTraits>> TraitsXMLName;
	static TMap<FString, TEnumAsByte<DnDDamageType>> DamageTypesXMLName;

	static TMap<FString, TEnumAsByte<DnDWeaponTraits>> InitTraitsNames();
	static TMap<FString, TEnumAsByte<DnDDamageType>> InitDamageTypeNames();
};

