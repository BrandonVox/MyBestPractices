// Copyright Brandon Vox.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "MAnimNotify_ComboWindow_Close.generated.h"

/**
 * 
 */
UCLASS()
class MYBESTPRACTICES_API UMAnimNotify_ComboWindow_Close : public UAnimNotify
{
	GENERATED_BODY()

public:
	UMAnimNotify_ComboWindow_Close();

	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation,
						const FAnimNotifyEventReference& EventReference) override;

	virtual FString GetNotifyName_Implementation() const override;
};
