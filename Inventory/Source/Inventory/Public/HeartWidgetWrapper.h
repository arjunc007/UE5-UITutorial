// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Widget.h"
#include "SHeartWidget.h"
#include "HeartWidgetWrapper.generated.h"

/**
 * 
 */
UCLASS()
class INVENTORY_API UHeartWidgetWrapper : public UWidget
{
	GENERATED_BODY()
public:
    // We use FSlateBrush instead of UTexture2D because it handles tiling/tinting for us
    UPROPERTY(EditAnywhere, Category = "Appearance")
    FSlateBrush FullHeart;

    UPROPERTY(EditAnywhere, Category = "Appearance")
    FSlateBrush HalfHeart;

    UPROPERTY(EditAnywhere, Category = "Appearance")
    FSlateBrush EmptyHeart;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    float CurrentHealth = 1.0f;

protected:
    virtual TSharedRef<SWidget> RebuildWidget() override;

    float GetHealthPercent() const { return CurrentHealth; }

    TSharedPtr<SHeartWidget> MySlateHeart;

};
