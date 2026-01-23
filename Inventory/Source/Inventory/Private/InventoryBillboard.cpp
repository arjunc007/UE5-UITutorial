// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryBillboard.h"

// Sets default values
AInventoryBillboard::AInventoryBillboard()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	WidgetComp = CreateDefaultSubobject<UWidgetComponent>(TEXT("DiegeticUI"));
	RootComponent = WidgetComp;

	WidgetComp->SetWidgetSpace(EWidgetSpace::World);

	WidgetComp->SetDrawSize(FVector2D(1920, 1080));

	WidgetComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);

}

// Called when the game starts or when spawned
void AInventoryBillboard::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AInventoryBillboard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

