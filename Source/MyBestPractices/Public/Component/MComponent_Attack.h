// Copyright Brandon Vox.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MComponent_Attack.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class MYBESTPRACTICES_API UMComponent_Attack : public UActorComponent
{
	GENERATED_BODY()

public: // Function
	// Sets default values for this component's properties
	UMComponent_Attack();
	void LocalInputPressed();
	void HandleComboWindow_Open(FName Name_Section_Next);
	void HandleComboWindow_Close();
	void EndAttack();
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;


	// Called every frame
	// virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected: // Function
	// Called when the game starts
	virtual void BeginPlay() override;

private: // Function
	void TryAttack();

	UFUNCTION(Server, Reliable)
	void Server_TryAttack();

	void PlayMontage_Attack();
	void Set_bIsAttacking(bool bNewValue);
	void OnSet_bIsAttacking();

	UFUNCTION()
	void OnRep_bIsAttacking(bool bOldValue);


	UFUNCTION()
	void HandleAnyMontageBlendingOut(UAnimMontage* InMontage, bool bInterrupted);


	UAnimInstance* GetAnimInstanceFromOwner() const;

private: // Property
	UPROPERTY(EditDefaultsOnly, Category = "MBP Settings")
	TObjectPtr<UAnimMontage> Montage_Attack;

	UPROPERTY(ReplicatedUsing = OnRep_bIsAttacking)
	bool bIsAttacking = false;

	UPROPERTY()
	TObjectPtr<UAudioComponent> Component_Audio_ComboWindow;

	UPROPERTY(EditDefaultsOnly, Category = "MBP Settings | Debug")
	TObjectPtr<USoundBase> Sound_ComboWindow;
};
