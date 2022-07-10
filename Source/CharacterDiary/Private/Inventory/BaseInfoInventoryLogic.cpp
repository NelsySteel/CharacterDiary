// Fill out your copyright notice in the Description page of Project Settings.


#include "Inventory/BaseInfoInventoryLogic.h"
#include "Inventory/BaseInventoryItemInfoDataAsset.h"

UBaseInventoryItemInfoDataAsset* UBaseInfoInventoryLogic::GetData()
{
	return Cast<UBaseInventoryItemInfoDataAsset>(data);
}
