// Copyright Brandon Vox.


#include "Character/MCharacter_Player.h"

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
