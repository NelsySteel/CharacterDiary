// Fill out your copyright notice in the Description page of Project Settings.


#include "Inventory/BaseInventoryItemInfoDataAsset.h"

#include "Inventory/BaseInfoInventoryLogic.h"

UBaseInventoryItemInfoDataAsset::UBaseInventoryItemInfoDataAsset()
{
	LogicClass = UBaseInfoInventoryLogic::StaticClass();
}
