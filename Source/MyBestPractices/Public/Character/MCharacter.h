// Copyright Brandon Vox.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MCharacter.generated.h"

class UMComponent_Attack;

UCLASS()
class MYBESTPRACTICES_API AMCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

// public:	
	// Called every frame
	// virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	// virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
protected: // Property
	UPROPERTY(VisibleDefaultsOnly)
	TObjectPtr<UMComponent_Attack> Component_Attack;
};
