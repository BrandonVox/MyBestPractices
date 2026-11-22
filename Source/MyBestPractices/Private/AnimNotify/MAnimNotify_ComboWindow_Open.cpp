// Copyright Brandon Vox.


#include "AnimNotify/MAnimNotify_ComboWindow_Open.h"

void UMAnimNotify_ComboWindow_Open::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation,
	const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);
}

FString UMAnimNotify_ComboWindow_Open::GetNotifyName_Implementation() const
{
	return Name_NextSection.ToString();
}

UMAnimNotify_ComboWindow_Open::UMAnimNotify_ComboWindow_Open()
{
	bIsNativeBranchingPoint = true;
}
