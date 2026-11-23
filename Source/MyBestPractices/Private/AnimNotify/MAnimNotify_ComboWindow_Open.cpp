// Copyright Brandon Vox.


#include "AnimNotify/MAnimNotify_ComboWindow_Open.h"

#include "Component/MComponent_Attack.h"

void UMAnimNotify_ComboWindow_Open::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation,
                                           const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);

	UMComponent_Attack* Comp_Attack = MeshComp->GetOwner()->FindComponentByClass<UMComponent_Attack>();
	if (Comp_Attack != nullptr)
	{
		Comp_Attack->HandleComboWindow_Open(Name_NextSection);
	}
}

FString UMAnimNotify_ComboWindow_Open::GetNotifyName_Implementation() const
{
	return Name_NextSection.ToString();
}

UMAnimNotify_ComboWindow_Open::UMAnimNotify_ComboWindow_Open()
{
	bIsNativeBranchingPoint = true;
}
