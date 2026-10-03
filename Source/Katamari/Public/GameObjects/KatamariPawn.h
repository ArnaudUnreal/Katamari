// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "KatamariPawn.generated.h"

struct FInputActionValue;

UCLASS()
class KATAMARI_API AKatamariPawn : public APawn
{
	GENERATED_BODY()

public:
	AKatamariPawn();
	virtual void Tick(float DeltaTime) override;
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="InputActions")
	TObjectPtr<class UInputAction> LeftStickAction;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="InputActions")
	TObjectPtr<class UInputAction> RightStickAction;

protected:
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
    UPROPERTY(EditDefaultsOnly, Category = "EnhancedInput")
    TObjectPtr<class UInputMappingContext> InputMapping;
	
	UFUNCTION()
	void LeftStick(const FInputActionValue& Value);
	void RightStick(const FInputActionValue& Value);

};
