// Copyright Brandon Vox.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "MAnimNotify_EndAttack.generated.h"

/**
 * 
 */
UCLASS()
class MYBESTPRACTICES_API UMAnimNotify_EndAttack : public UAnimNotify
{
	GENERATED_BODY()

public:
	UMAnimNotify_EndAttack();
	
	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation,
					const FAnimNotifyEventReference& EventReference) override;

	virtual FString GetNotifyName_Implementation() const override;
};
