// Copyright Brandon Vox.


#include "AnimNotify/MAnimNotify_EndAttack.h"

#include "Component/MComponent_Attack.h"

void UMAnimNotify_EndAttack::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation,
                                    const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);

	// bisAttacking = false
	// component_attack
	// owner actor
	AActor* Actor_Owner = MeshComp->GetOwner();
	UMComponent_Attack* Component_Attack = Actor_Owner->FindComponentByClass<UMComponent_Attack>();
	if (Component_Attack != nullptr)
	{
		Component_Attack->EndAttack();
	}
}
