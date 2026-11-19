// Copyright Brandon Vox.


#include "Component/MComponent_Attack.h"

#include "Net/UnrealNetwork.h"

// Sets default values for this component's properties
UMComponent_Attack::UMComponent_Attack()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
	SetIsReplicatedByDefault(true);
	// ...
}

void UMComponent_Attack::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UMComponent_Attack, bIsAttacking, COND_None, REPNOTIFY_OnChanged);
}

// Called when the game starts
void UMComponent_Attack::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
// void UMComponent_Attack::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
// {
// 	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
//
// 	// ...
// }

void UMComponent_Attack::LocalInputPressed()
{
	// UE_LOG(LogTemp, Warning, TEXT("Attack Pressed"));


	if (GetOwner()->HasAuthority()) // server
	{
		if (!bIsAttacking)
		{
			Set_bIsAttacking(true);
		}
	}
	else // Not Server - Clients
	{
		Server_TryAttack();
	}
}

void UMComponent_Attack::TryAttack()
{
	if (!bIsAttacking)
	{
		Set_bIsAttacking(true);
	}
}

void UMComponent_Attack::Server_TryAttack_Implementation()
{
	// Server
	if (!bIsAttacking)
	{
		Set_bIsAttacking(true);
	}
}

void UMComponent_Attack::PlayMontage_Attack()
{
	USkeletalMeshComponent* Comp_Mesh = GetOwner()->FindComponentByClass<USkeletalMeshComponent>();
	if (Comp_Mesh != nullptr)
	{
		UAnimInstance* AnimInstance_My = Comp_Mesh->GetAnimInstance();
		AnimInstance_My->Montage_Play(Montage_Attack);
	}
}

void UMComponent_Attack::EndAttack()
{
	Set_bIsAttacking(false);
}

void UMComponent_Attack::Set_bIsAttacking(bool bNewValue)
{
	if (GetOwnerRole() == ROLE_Authority)
	{
		bIsAttacking = bNewValue;
		OnSet_bIsAttacking();
	}
}

void UMComponent_Attack::OnSet_bIsAttacking()
{
	if (bIsAttacking)
	{
		PlayMontage_Attack();
	}
	else
	{
		// UE_LOG(LogTemp, Warning, TEXT("bIsAttacking = false"));
	}
}

void UMComponent_Attack::OnRep_bIsAttacking(bool bOldValue)
{
	OnSet_bIsAttacking();
}
