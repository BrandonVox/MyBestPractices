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

	GetAnimInstanceFromOwner()
		->OnMontageBlendingOut.AddDynamic(this, &UMComponent_Attack::HandleAnyMontageBlendingOut);
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
	UE_LOG(LogTemp, Warning, TEXT("PlayMontage_Attack"));

	USkeletalMeshComponent* Comp_Mesh = GetOwner()->FindComponentByClass<USkeletalMeshComponent>();
	if (Comp_Mesh != nullptr)
	{
		UAnimInstance* AnimInstance_My = Comp_Mesh->GetAnimInstance();
		AnimInstance_My->Montage_Play(Montage_Attack);
	}
}

void UMComponent_Attack::HandleComboWindow_Open(FName Name_Section_Next)
{
	UE_LOG(LogTemp, Warning, TEXT("HandleComboWindow_Open"));

	UAnimInstance* AnimInstance_Owner = GetAnimInstanceFromOwner();
	FName Name_Section_Current = AnimInstance_Owner->Montage_GetCurrentSection(Montage_Attack);

	AnimInstance_Owner
		->Montage_SetNextSection(Name_Section_Current, Name_Section_Next, Montage_Attack);
}

void UMComponent_Attack::HandleComboWindow_Close()
{
	UE_LOG(LogTemp, Warning, TEXT("HandleComboWindow_Close"));
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
	// client
	if (bIsAttacking == false)
	{
		UAnimInstance* AnimInstance_Owner = GetAnimInstanceFromOwner();
		if (AnimInstance_Owner->Montage_IsActive(Montage_Attack))
		{
			AnimInstance_Owner->Montage_Stop(Montage_Attack->GetDefaultBlendOutTime(), Montage_Attack);
		}
	}
}

void UMComponent_Attack::HandleAnyMontageBlendingOut(UAnimMontage* InMontage, bool bInterrupted)
{
	if (InMontage != Montage_Attack)
	{
		return;
	}

	UE_LOG(LogTemp, Warning, TEXT("Handle Attacking Montage Blending Out"));


	EndAttack();
}

UAnimInstance* UMComponent_Attack::GetAnimInstanceFromOwner() const
{
	return GetOwner()->FindComponentByClass<USkeletalMeshComponent>()->GetAnimInstance();
}
