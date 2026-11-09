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
}
