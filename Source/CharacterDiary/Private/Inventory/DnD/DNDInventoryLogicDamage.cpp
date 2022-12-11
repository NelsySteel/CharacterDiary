// Fill out your copyright notice in the Description page of Project Settings.


#include "Inventory/DnD/DNDInventoryLogicDamage.h"
#include "XmlNode.h"

TMap<FString, TEnumAsByte<DnDWeaponTraits>> UDnDInventoryLogicDamage::TraitsXMLName			= UDnDInventoryLogicDamage::InitTraitsNames();
TMap<FString, TEnumAsByte<DnDDamageType>>	UDnDInventoryLogicDamage::DamageTypesXMLName	= UDnDInventoryLogicDamage::InitDamageTypeNames();

TMap<FString, TEnumAsByte<DnDWeaponTraits>> UDnDInventoryLogicDamage::InitTraitsNames()
{
	TMap<FString, TEnumAsByte<DnDWeaponTraits>> result;
	result.Add("Two Handed",	DnDWeaponTraits::TWO_HANDED);
	result.Add("Ranged",		DnDWeaponTraits::RANGED);
	result.Add("Reach",		DnDWeaponTraits::REACH);
	result.Add("Ammunition",	DnDWeaponTraits::NEEDS_AMMO);
	result.Add("Reloading",	DnDWeaponTraits::RELOADING);
	result.Add("Light",		DnDWeaponTraits::LIGHT);
	result.Add("Thrown",		DnDWeaponTraits::THROWN);
	result.Add("Finesse",		DnDWeaponTraits::FINESSE);
	result.Add("Heavy",		DnDWeaponTraits::HEAVY);
	result.Add("Versatile",	DnDWeaponTraits::VERSATILE);
	result.Add("Improvised",	DnDWeaponTraits::IMPROVISED);
	result.Add("Silvered",		DnDWeaponTraits::SILVERED);
	result.Add("Special",		DnDWeaponTraits::SPECIAL);
	result.Add("Undefined",	DnDWeaponTraits::UNDEFINED);
	return result;
}

TMap<FString, TEnumAsByte<DnDDamageType>> UDnDInventoryLogicDamage::InitDamageTypeNames()
{
	TMap<FString, TEnumAsByte<DnDDamageType>> result;
	result.Add("Piercing",		DnDDamageType::PIERCING);
	result.Add("Bludgeoning",	DnDDamageType::BLUGGEONING);
	result.Add("Slashing",		DnDDamageType::SLASHING);
	result.Add("Acid",			DnDDamageType::ACID);
	result.Add("Cold",			DnDDamageType::COLD);
	result.Add("Fire",			DnDDamageType::FIRE);
	result.Add("Force",		DnDDamageType::FORCE);
	result.Add("Lightning",	DnDDamageType::LIGHTNING);
	result.Add("Necrotic",		DnDDamageType::NECROTIC);
	result.Add("Poison",		DnDDamageType::POISON);
	result.Add("Psychic",		DnDDamageType::PSYCHIC);
	result.Add("Radiant",		DnDDamageType::RADIANT);
	result.Add("Thunder",		DnDDamageType::THUNDER);
	result.Add("Custom",		DnDDamageType::CUSTOM);
	return result;
}


bool UDnDInventoryLogicDamage::LoadFromXML(FXmlNode* rootNode)
{
	if (!rootNode)
	{
		return false;
	}

	if (const FXmlNode* traitsNode = rootNode->FindChildNode("Traits"))
	{
		for (const auto& traitNode : traitsNode->GetChildrenNodes())
		{
			const FString traitStr = traitNode->GetContent();
			if (TraitsXMLName.Find(traitStr))
			{
				WeaponTraits.Add(TraitsXMLName[traitStr]);
			}
			else
			{
				//ToDo Warning - unknown trait
			}
		}
	}

	if (const FXmlNode* damageOptionsNode = rootNode->FindChildNode("DamageOptions"))
	{
		for (const auto& damageOptionNode : damageOptionsNode->GetChildrenNodes())
		{
			FDamageOption damageOption;
			if (const FXmlNode* attackDescNode = damageOptionNode->FindChildNode("AttackDesc"))
			{
				const FString traitStr = attackDescNode->GetContent();
				damageOption.AttackDesc = traitStr;
			}
			else
			{
				damageOption.AttackDesc = "Basic";
			}

			if (const FXmlNode* damageTypeNode = damageOptionNode->FindChildNode("DamageType"))
			{
				const FString damageTypeStr = damageTypeNode->GetContent();
				if (DamageTypesXMLName.Find(damageTypeStr))
				{

					damageOption.DamageType = DamageTypesXMLName[damageTypeStr];
				}
				else
				{
					//ToDo Warning - unknown damage type
				}
			}
			else
			{
				//ToDo Warning - no damage type
				damageOption.DamageType = DnDDamageType::CUSTOM;
			}

			if (const FXmlNode* damageNode = damageOptionNode->FindChildNode("Damage"))
			{
				const FString damageStr = damageNode->GetContent();
				FString diceCountStr;
				FString diceStr;
				damageStr.Split("d", &diceCountStr, &diceStr);
				if (!diceCountStr.IsEmpty() && diceCountStr.IsNumeric())
				{
					int32 diceCountValue = FCString::Atoi(*diceCountStr);
					damageOption.DamageDiceCount = diceCountValue;
				}
				else
				{
					//ToDo Warning - wrong damage string (count error, before d)
				};

				if (!diceStr.IsEmpty() && diceStr.IsNumeric())
				{
					int32 diceValue = FCString::Atoi(*diceStr);
					TEnumAsByte<DiceType> diceEnumValue = DiceType::UNKNOWN;
					switch (diceValue)
					{
					case 4: diceEnumValue = DiceType::D4; break;
					case 6: diceEnumValue = DiceType::D6; break;
					case 8: diceEnumValue = DiceType::D8; break;
					case 10: diceEnumValue = DiceType::D10; break;
					case 12: diceEnumValue = DiceType::D12; break;
					case 20: diceEnumValue = DiceType::D20; break;
					default: diceEnumValue = DiceType::UNKNOWN;
					};

					damageOption.DamageDice = diceEnumValue;
				}
				else
				{
					//ToDo Warning - wrong damage string (dice error, after d)
				}
			}
			else
			{
				//ToDo Error - no damage info
				return false;
			}

			DamageOptions.Add(damageOption);
		}
	}

	return true;
}
