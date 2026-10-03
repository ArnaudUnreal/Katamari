// Fill out your copyright notice in the Description page of Project Settings.


#include "GameObjects/KatamariPawn.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"


// Sets default values
AKatamariPawn::AKatamariPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AKatamariPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

void AKatamariPawn::LeftStick(const FInputActionValue& Value)
{
	FVector2D LeftStickValue = Value.Get<FVector2D>();
	float LeftStickValueX = LeftStickValue.X;
	float LeftStickValueY = LeftStickValue.Y;
}

void AKatamariPawn::RightStick(const FInputActionValue& Value)
{
	FVector2D RightStickValue = Value.Get<FVector2D>();
	float RightStickValueX = RightStickValue.X;
	float RightStickValueY = RightStickValue.Y;
}
// Called every frame
void AKatamariPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AKatamariPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	APlayerController* PlayerController = Cast<APlayerController>(GetController());
 
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer());
    
	Subsystem->ClearAllMappings();
	Subsystem->AddMappingContext(InputMapping, 0);
	
	UEnhancedInputComponent* Input = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	Input->BindAction(LeftStickAction, ETriggerEvent::Triggered, this, &AKatamariPawn::LeftStick);
	Input->BindAction(RightStickAction, ETriggerEvent::Triggered, this, &AKatamariPawn::RightStick);
	
}

