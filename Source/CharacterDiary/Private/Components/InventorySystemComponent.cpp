// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/InventorySystemComponent.h"

#include "XmlFile.h"
#include "XmlNode.h"

// Sets default values for this component's properties
UInventorySystemComponent::UInventorySystemComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	for (int i = 0; i < static_cast<uint8>(EBaseCurrency::CURRENCY_COUNT); i++)
	{
		Wallet.Values.Add(static_cast<EBaseCurrency>(i), 0);
	}
	// ...
}

void UInventorySystemComponent::Initialize_Implementation()
{
	
}


void UInventorySystemComponent::AddMoneyStruct(FBaseCurrency currency)
{
}

void UInventorySystemComponent::AddMoney(EBaseCurrency currency, int32 value)
{

}

// Called when the game starts
void UInventorySystemComponent::BeginPlay()
{

	Super::BeginPlay();
	// ...
	
}


// Called every frame
void UInventorySystemComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

