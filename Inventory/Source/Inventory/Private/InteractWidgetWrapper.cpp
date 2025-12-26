// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractWidgetWrapper.h"

TSharedRef<SWidget> UInteractWidgetWrapper::RebuildWidget()
{
	SlateInteractWidget = SNew(SSInteractWidget)
		.BackgroundBrush(&BackgroundBrush)
		.ItemTypeBrush(ItemTypeBrush)
		.ItemData(ItemData);

	SlateInteractWidget->SetItemInfo(ItemData);
	return SlateInteractWidget.ToSharedRef();
}

void UInteractWidgetWrapper::ReleaseSlateResources(bool bReleaseChildren)
{
	Super::ReleaseSlateResources(bReleaseChildren);

	SlateInteractWidget.Reset();
}

void UInteractWidgetWrapper::SetData(const FSlot& ItemSlot)
{
	ItemData = ItemSlot.ItemHandle.GetRow<FSItem>(TEXT("Context"));

	switch (ItemSlot.ItemType)
	{
	case EItemTypes::Sword:
		ItemTypeBrush = &SwordIcon;
		break;
	case EItemTypes::Shield:
		ItemTypeBrush = &ShieldIcon;
		break;
	case EItemTypes::Eatable:
		ItemTypeBrush = &EatableIcon;
		break;
	}
}