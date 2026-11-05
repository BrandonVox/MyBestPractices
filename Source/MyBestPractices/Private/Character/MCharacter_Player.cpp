// Copyright Brandon Vox.


#include "Character/MCharacter_Player.h"

#include "EnhancedInputComponent.h"
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

	// make the camera follow the controller's rotation
	SpringArmComponent->bUsePawnControlRotation = true;
	CameraComponent->bUsePawnControlRotation = false;

	// controller rotation has 3 values: yaw pitch roll
	bUseControllerRotationYaw = false;
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
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

void AMCharacter_Player::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent);

	EnhancedInputComponent->BindAction
	(
		IA_Jump,
		ETriggerEvent::Triggered,
		this,
		&AMCharacter_Player::HandleIA_Jump_Triggered
	);

	EnhancedInputComponent->BindAction
	(
		IA_Look,
		ETriggerEvent::Triggered,
		this,
		&AMCharacter_Player::HandleIA_Look_Triggered
	);

	EnhancedInputComponent->BindAction
	(
		IA_Move,
		ETriggerEvent::Triggered,
		this,
		&AMCharacter_Player::HandleIA_Move_Triggered
	);
}

void AMCharacter_Player::HandleIA_Jump_Triggered()
{
	// UE_LOG(LogTemp, Warning, TEXT("HandleIA_Jump_Triggered"));
	Jump();
}

void AMCharacter_Player::HandleIA_Look_Triggered(const FInputActionValue& InputActionValue)
{
	// X Y
	FVector2D AxisValue = InputActionValue.Get<FVector2D>();

	// UE_LOG(LogTemp, Warning, TEXT("Look X = %f, Y = %f"), AxisValue.X, AxisValue.Y);
	AddControllerYawInput(AxisValue.X); // looking left right Axis.X
	AddControllerPitchInput(AxisValue.Y); // looking up down Axis.y
}

void AMCharacter_Player::HandleIA_Move_Triggered(const FInputActionValue& InputActionValue)
{
	FVector2D AxisValue = InputActionValue.Get<FVector2D>().GetClampedToMaxSize(1.f);

	UE_LOG(LogTemp, Warning, TEXT("Moment Input Length = %f"), AxisValue.Length());
	// Axis.X DA Right Left
	// Axis.Y WS Forward Backward

	// Movement Component
	// Movement Input
	// Direction ScaleValue
	// Forward Direction  of character
	// Right Direction of character
	AddMovementInput(GetActorForwardVector(), AxisValue.Y);
	AddMovementInput(GetActorRightVector(), AxisValue.X);
}
