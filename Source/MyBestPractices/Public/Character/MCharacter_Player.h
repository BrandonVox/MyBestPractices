// Copyright Brandon Vox.

#pragma once

#include "CoreMinimal.h"
#include "Character/MCharacter.h"
#include "MCharacter_Player.generated.h"

class UCameraComponent;
class USpringArmComponent;
/**
 * 
 */
UCLASS()
class MYBESTPRACTICES_API AMCharacter_Player : public AMCharacter
{
	GENERATED_BODY()
	
public:
	AMCharacter_Player();
	
	
private: // Property
	UPROPERTY()
	TObjectPtr<USpringArmComponent> SpringArmComponent; // Camera boom
	
	UPROPERTY()
	TObjectPtr<UCameraComponent> CameraComponent;
	
};
