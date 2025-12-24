// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "InventoryStructs.generated.h"

UENUM(BlueprintType)
enum class EItemTypes : uint8
{
    Sword      UMETA(DisplayName = "Sword"),
    Shield     UMETA(DisplayName = "Shield"),
    Eatable    UMETA(DisplayName = "Eatable"),
};

USTRUCT(BlueprintType)
struct FSItem : public FTableRowBase
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Data")
    FText Name;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Data")
    FText Description;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Data")
    UTexture2D* Thumbnail;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Data")
    int StackSize;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Data")
    float Power;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Data")
    UStaticMesh* Mesh;
};

USTRUCT(BlueprintType)
struct FSlot
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Slot")
    FDataTableRowHandle ItemHandle;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Slot")
    int Quantity;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Slot")
    EItemTypes ItemType;
};