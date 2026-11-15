// Copyright Brandon Vox.


#include "Component/MComponent_Attack.h"

// Sets default values for this component's properties
UMComponent_Attack::UMComponent_Attack()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

// Called when the game starts
void UMComponent_Attack::BeginPlay()
{
	Super::BeginPlay();

	// ...
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
	UE_LOG(LogTemp, Warning, TEXT("Attack Pressed"));


	if (GetOwner()->HasAuthority()) // server
	{
		TryAttack();
	}
	else // Not Server - Clients
	{
		Server_TryAttack();
	}

	/*
	 *		Local Role
	 *		Local Role tells us the network role of an Actor on the local machine.
	 *		The same Actor can have a different role on each machine.
	 *		On the server, the Actor has the role Authority.
	 *		On the client, the Actor has the role Proxy.
	 *		On the client that controls this Actor, it has the role Autonomous Proxy.
	 *		On the other clients, it has the role Simulated Proxy.
	 *		We use the function GetLocalRole to check.
	 */
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
	TryAttack();
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
	bIsAttacking = bNewValue;
	OnSet_bIsAttacking();
}

void UMComponent_Attack::OnSet_bIsAttacking()
{
	if (bIsAttacking)
	{
		PlayMontage_Attack();
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("bIsAttacking = false"));
	}
}
