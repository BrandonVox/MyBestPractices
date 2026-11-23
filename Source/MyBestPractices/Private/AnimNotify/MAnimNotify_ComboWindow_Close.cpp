// Copyright Brandon Vox.


#include "AnimNotify/MAnimNotify_ComboWindow_Close.h"

#include "Component/MComponent_Attack.h"

void UMAnimNotify_ComboWindow_Close::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation,
                                            const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);

	UMComponent_Attack* Comp_Attack = MeshComp->GetOwner()->FindComponentByClass<UMComponent_Attack>();
	if (Comp_Attack != nullptr)
	{
		Comp_Attack->HandleComboWindow_Close();
	}
}

FString UMAnimNotify_ComboWindow_Close::GetNotifyName_Implementation() const
{
	return FString(TEXT("CloseCombo"));
}

UMAnimNotify_ComboWindow_Close::UMAnimNotify_ComboWindow_Close()
{
	bIsNativeBranchingPoint = true;
}
