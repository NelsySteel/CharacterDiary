// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/InventorySystemComponent.h"

#include "XmlFile.h"
#include "XmlNode.h"
#include "Inventory/IInventoryObject.h"


// Sets default values for this component's properties
UInventorySystemComponent::UInventorySystemComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	
}

void UInventorySystemComponent::Initialize_Implementation()
{
	LoadDefaultItemsFromXML(L"E:/Unreal Projects/CharacterDiary 5.1/Content/Data/DefaultItems.xml");
}

UIInventoryComponentLogic* UInventorySystemComponent::CreateLogicFromName(const FString& name)
{
	return nullptr;
}

void UInventorySystemComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UInventorySystemComponent::LoadDefaultItemsFromXML(const FString& fileName)
{
	FXmlFile* xmlFile = new FXmlFile(fileName);
	FXmlNode* root = xmlFile->GetRootNode();
	for (FXmlNode* itemNode : root->GetChildrenNodes())
	{
		UIInventoryObject* item = NewObject<UIInventoryObject>(this, FName(itemNode->GetTag()));
		for (FXmlNode* componentNode : itemNode->GetChildrenNodes())
		{
			if (UIInventoryComponentLogic* logic = CreateLogicFromName(componentNode->GetTag()))
			{
				item->AddLogic(logic);
				logic->LoadFromXML(componentNode);
			}
		}
		Items.Add(item);
	}
}

void UInventorySystemComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

