// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "IInventoryComponentLogic.generated.h"


class FXmlNode;
class UIInventoryItemInfoObject;
/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class CHARACTERDIARY_API UIInventoryComponentLogic : public UObject
{
	GENERATED_BODY()
public:
	UIInventoryComponentLogic() = default;
	~UIInventoryComponentLogic() = default;

	virtual bool LoadFromXML(FXmlNode* rootNode);
};
