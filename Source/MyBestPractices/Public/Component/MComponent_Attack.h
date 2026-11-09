// Copyright Brandon Vox.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MComponent_Attack.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYBESTPRACTICES_API UMComponent_Attack : public UActorComponent
{
	GENERATED_BODY()

public:	// Function
	// Sets default values for this component's properties
	UMComponent_Attack();
	void LocalInputPressed();
	
	// Called every frame
	// virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

		
};
