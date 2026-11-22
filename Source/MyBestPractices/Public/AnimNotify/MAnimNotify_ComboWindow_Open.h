// Copyright Brandon Vox.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "MAnimNotify_ComboWindow_Open.generated.h"

/**
 * 
 */
UCLASS()
class MYBESTPRACTICES_API UMAnimNotify_ComboWindow_Open : public UAnimNotify
{
	GENERATED_BODY()
	
	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation,
					const FAnimNotifyEventReference& EventReference) override;

	virtual FString GetNotifyName_Implementation() const override;
	
public:
	UMAnimNotify_ComboWindow_Open();
};
