// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InventoryStructs.h"
#include "SSInteractWidget.h"
#include "InteractWidgetWrapper.generated.h"

/**
 * 
 */
UCLASS()
class INVENTORY_API UInteractWidgetWrapper : public UUserWidget
{
	GENERATED_BODY()

public:
	void SetData(const FSlot& itemSlot);

	UPROPERTY(EditAnywhere, Category = "Appearance")
	FSlateBrush BackgroundBrush;

protected:
	virtual TSharedRef<SWidget> RebuildWidget() override;
	virtual void ReleaseSlateResources(bool bReleaseChildren) override;

private:
	TSharedPtr<SSInteractWidget> SlateInteractWidget;
	FSItem* ItemData;
};
