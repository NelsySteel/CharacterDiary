// Fill out your copyright notice in the Description page of Project Settings.


#include "XmlNode.h"
#include "Inventory/DnD/DnDInventoryLogicBaseInfo.h"

bool UDnDInventoryLogicBaseInfo::LoadFromXML(FXmlNode* rootNode)
{
	if (!rootNode)
	{
		return false;
	}

	if (const FXmlNode * nameNode = rootNode->FindChildNode("Name"))
	{
		Name = nameNode->GetContent();
	}
	if (const FXmlNode* weightNode = rootNode->FindChildNode("Weight"))
	{
		const FString weightStr = weightNode->GetContent();
		if (weightStr.IsNumeric())
		{
			Weight = FCString::Atoi(*weightStr);
		}
	}
	if (const FXmlNode* costNode = rootNode->FindChildNode("Cost"))
	{
		const FString costStr = costNode->GetContent();
		if (costStr.IsNumeric())
		{
			Cost = FCString::Atoi(*costStr);
		}
	}
	if (const FXmlNode* amountNode = rootNode->FindChildNode("Amount"))
	{
		const FString amountStr = amountNode->GetContent();
		if (amountStr.IsNumeric())
		{
			Amount = FCString::Atoi(*amountStr);
		}
	}
	return true;
}
