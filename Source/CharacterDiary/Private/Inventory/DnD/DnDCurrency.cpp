// Fill out your copyright notice in the Description page of Project Settings.


#include "Inventory/DnD/DnDCurrency.h"

FDnDCurrency::FDnDCurrency()
{
	for (int i = 0; i < static_cast<uint8>(EDnDCurrency::CURRENCY_COUNT); i++)
	{
		Values.Add(static_cast<EDnDCurrency>(i), 0);
	}
}
