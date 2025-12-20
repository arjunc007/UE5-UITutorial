// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Widget.h"
#include "InventoryComponent.h"
#include "SHealthBarWidget.h"
#include "HealthBarWidgetWrapper.generated.h"

/**
 * 
 */
UCLASS()
class INVENTORY_API UHealthBarWidgetWrapper : public UWidget
{
	GENERATED_BODY()
protected:
	virtual TSharedRef<SWidget> RebuildWidget() override;

    TSharedPtr<SHealthBarWidget> SlateHealthBar;

public:
    void SetSourceComponent(UInventoryComponent* InComp);
    virtual void ReleaseSlateResources(bool bReleaseChildren) override;

    // We use FSlateBrush instead of UTexture2D because it handles tiling/tinting for us
    UPROPERTY(EditAnywhere, Category = "Appearance")
    FSlateBrush FullHeart;

    UPROPERTY(EditAnywhere, Category = "Appearance")
    FSlateBrush HalfHeart;

    UPROPERTY(EditAnywhere, Category = "Appearance")
    FSlateBrush EmptyHeart;

private:
    UFUNCTION()
    void OnHealthUpdate(float NewHealth, int MaxHearts);

    float GetHealthFromComponent() const;
    int GetMaxHealthFromComponent() const;
    TWeakObjectPtr<UInventoryComponent> SourceComp;
};
