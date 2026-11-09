// Copyright Brandon Vox.

#pragma once

#include "CoreMinimal.h"
#include "Character/MCharacter.h"
#include "MCharacter_Player.generated.h"

struct FInputActionValue;
class UInputAction;
class UInputMappingContext;
class UCameraComponent;
class USpringArmComponent;
/**
 * 
 */
UCLASS()
class MYBESTPRACTICES_API AMCharacter_Player : public AMCharacter
{
	GENERATED_BODY()

public: // Function
	AMCharacter_Player();

	virtual void PawnClientRestart() override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private: // Function
	void SetupInputMappingContext();
	void HandleIA_Jump_Triggered();
	void HandleIA_Look_Triggered(const FInputActionValue& InputActionValue);
	void HandleIA_Move_Triggered(const FInputActionValue& InputActionValue);
	void HandleIA_Attack_Triggered(const FInputActionValue& InputActionValue);

private: // Property
	UPROPERTY(VisibleDefaultsOnly)
	TObjectPtr<USpringArmComponent> SpringArmComponent; // Camera boom

	UPROPERTY(VisibleDefaultsOnly)
	TObjectPtr<UCameraComponent> CameraComponent;

	UPROPERTY(EditDefaultsOnly, Category = "MBP Settings | Input")
	TObjectPtr<UInputMappingContext> IMC_BasicMovement;
	
	UPROPERTY(EditDefaultsOnly, Category = "MBP Settings | Input")
	TObjectPtr<UInputMappingContext> IMC_Combat;

	UPROPERTY(EditDefaultsOnly, Category = "MBP Settings | Input")
	TObjectPtr<UInputAction> IA_Jump;
	
	UPROPERTY(EditDefaultsOnly, Category = "MBP Settings | Input")
	TObjectPtr<UInputAction> IA_Look;
	
	UPROPERTY(EditDefaultsOnly, Category = "MBP Settings | Input")
	TObjectPtr<UInputAction> IA_Move;
	
	UPROPERTY(EditDefaultsOnly, Category = "MBP Settings | Input")
	TObjectPtr<UInputAction> IA_Attack;
};
