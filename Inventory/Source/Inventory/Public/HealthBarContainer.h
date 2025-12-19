// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HealthBarWidgetWrapper.h"
#include "InventoryComponent.h"
#include "HealthBarContainer.generated.h"

/**
 * 
 */
UCLASS()
class INVENTORY_API UHealthBarContainer : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(meta = (BindWidget))
	UHealthBarWidgetWrapper* HealthBarWidget;
	
    void InitializeHealthBar(UInventoryComponent* Comp)
    {
        if (HealthBarWidget)
        {
            HealthBarWidget->SetSourceComponent(Comp);
        }
    }
};
