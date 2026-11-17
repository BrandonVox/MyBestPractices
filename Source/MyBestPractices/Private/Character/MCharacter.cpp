// Copyright Brandon Vox.


#include "Character/MCharacter.h"

#include "Component/MComponent_Attack.h"

// Sets default values
AMCharacter::AMCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	bReplicates = true;
	SetMinNetUpdateFrequency(10.f);
	SetNetUpdateFrequency(100.f);
	/*
	 * Net Update Frequency controls how often an actor is considered for replication, measured in updates per second
	 * Being “considered for replication” does not mean data is sent every time.
	 * It also depends on property changes, relevancy, dormancy, and available bandwidth.
	 * Net Update Frequency is not the same as FPS or Tick frequency.
	 */
	
	/*
	 * For example, if we set Net Update Frequency to 100,
	 * the server considers the actor for replication 100 times per second.
	 * That means the server checks every 0.01 seconds.
	 * The server does not send property updates every time it checks.
	 * Server only sends data when there are changes to synchronize.
	 */

	Component_Attack = CreateDefaultSubobject<UMComponent_Attack>(TEXT("Component_Attack"));
}

// Called when the game starts or when spawned
void AMCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
// void AMCharacter::Tick(float DeltaTime)
// {
// 	Super::Tick(DeltaTime);
//
// }

// Called to bind functionality to input
// void AMCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
// {
// 	Super::SetupPlayerInputComponent(PlayerInputComponent);
//
// }
