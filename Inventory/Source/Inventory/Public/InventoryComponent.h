// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Blueprint/UserWidget.h"
#include "Delegates/DelegateCombinations.h"
#include "InventoryComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnHealthChanged, float, NewHealth, int, MaxHearts);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class INVENTORY_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventoryComponent();

	UPROPERTY(BlueprintAssignable, Category = "Events")
	FOnHealthChanged OnHealthChanged;

	void ModifyHealth(float Delta)
	{
		Health = FMath::Clamp(Health + Delta, 0.0f, (float)MaxHealth);

		// SHOUT to everyone listening!
		if (OnHealthChanged.IsBound())
		{
			OnHealthChanged.Broadcast(Health, MaxHealth);
		}
	}

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
	float Health = 5.5f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
	int MaxHealth = 20;

	UPROPERTY(EditAnywhere, Category = "UI")
	TSubclassOf<UUserWidget> HealthBarClassToSpawn;
	UPROPERTY(EditAnywhere, Category = "UI")
	TSubclassOf<UUserWidget> InventoryClassToSpawn;
	UPROPERTY(EditAnywhere, Category = "UI")
	TSubclassOf<UUserWidget> InteractClassToSpawn;

	UPROPERTY()
	UUserWidget* HealthBarWidget;
	UPROPERTY()
	UUserWidget* InventoryWidget;
	UPROPERTY()
	UUserWidget* InteractWidget;

private:
	void OnDebugHeal();
	void OnDebugDamage();

	bool TraceItemToPickup() const;
};
