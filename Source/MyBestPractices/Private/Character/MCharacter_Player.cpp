// Copyright Brandon Vox.


#include "Character/MCharacter_Player.h"

#include "EnhancedInputSubsystems.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

AMCharacter_Player::AMCharacter_Player()
{
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));

	// attach camera to the root component of the character
	// attach the camera to camera boom first
	// attach the camera boom is the root component
	CameraComponent->SetupAttachment(SpringArmComponent, USpringArmComponent::SocketName);
	SpringArmComponent->SetupAttachment(GetRootComponent());
}

void AMCharacter_Player::PawnClientRestart()
{
	Super::PawnClientRestart();
	SetupInputMappingContext();
}

void AMCharacter_Player::SetupInputMappingContext()
{
	// Add IMC -> Enhanced Input Subsystem
	// Only player can control the character
	// Local Player
	// Player Controller

	// This Character is possessed by Player Controller
	// Apqawn

	APlayerController* MyPlayerController = GetController<APlayerController>();
	check(MyPlayerController);

	ULocalPlayer* MyLocalPlayer = MyPlayerController->GetLocalPlayer();

	UEnhancedInputLocalPlayerSubsystem* EnhancedInputSubsystem =
		ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(MyLocalPlayer);
	
	check(EnhancedInputSubsystem);

	if (!EnhancedInputSubsystem->HasMappingContext(IMC_BasicMovement))
	{
		EnhancedInputSubsystem->AddMappingContext(IMC_BasicMovement, 0);
	}
}
