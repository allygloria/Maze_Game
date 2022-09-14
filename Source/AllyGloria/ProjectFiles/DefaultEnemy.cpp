// Fill out your copyright notice in the Description page of Project Settings.

#include "AllyGloriaCharacter.h"
#include "DefaultEnemy.h"
#include "Pickup.h"
#include "AIController.h"

// Sets default values
ADefaultEnemy::ADefaultEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Default health value for the enemy.
	health = 1.0f;
	hasTakenDamage = false;
	isDead = false;

	//Create the sphere components that dictate when the enemy will attack based on location. 
	AgroSphere = CreateDefaultSubobject <USphereComponent>(TEXT("AgroSphere"));
	AgroSphere->SetupAttachment(GetRootComponent());
	AgroSphere->InitSphereRadius(500.f);

	CombatSphere = CreateDefaultSubobject <USphereComponent>(TEXT("CombatSphere"));
	CombatSphere->SetupAttachment(GetRootComponent());
	CombatSphere->InitSphereRadius(400.f);
}

// Called when the game starts or when spawned
void ADefaultEnemy::BeginPlay()
{
	Super::BeginPlay();
	
	//Reference to the AI controller
	AIController = Cast<AAIController>(GetController());

	AgroSphere->OnComponentBeginOverlap.AddDynamic(this, &ADefaultEnemy::AgroSphereOnOverlapBegin);
	AgroSphere->OnComponentEndOverlap.AddDynamic(this, &ADefaultEnemy::AgroSphereOnOverlapEnd);

	CombatSphere->OnComponentBeginOverlap.AddDynamic(this, &ADefaultEnemy::CombatSphereOnOverlapBegin);
	CombatSphere->OnComponentEndOverlap.AddDynamic(this, &ADefaultEnemy::CombatSphereOnOverlapEnd);

}

// Called every frame
void ADefaultEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
//Subtracts the amount of damage done from the health of the enemy. 
void ADefaultEnemy::TakeDamage(float damage)
{
	health -= damage;

	//If the enemies health is less than or equal to 0, they "die".
	if (health <= 0.0f)
	{
		isDead = true;
		//When enemy dies, destroy the actor. 
		//if (isDead)
		//{
			//Could not figure out how to add a slight delay before this. 
			//Destroy();

			
		//}

		
		
		
	}
	//Otherwise, they have just taken damage. 
	else
	{
		hasTakenDamage = true;
	}
}
// Called to bind functionality to input
void ADefaultEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ADefaultEnemy::AgroSphereOnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor)
	{
		AAllyGloriaCharacter* AllyGloriaCharacter = Cast<AAllyGloriaCharacter>(OtherActor);
		if (AllyGloriaCharacter)
		{
			MoveToTarget(AllyGloriaCharacter);
		}

	}
}


 void ADefaultEnemy::AgroSphereOnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
 {

 }



 void  ADefaultEnemy::CombatSphereOnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

}

 void  ADefaultEnemy::CombatSphereOnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
 {

 }
 void ADefaultEnemy::MoveToTarget(AAllyGloriaCharacter* Target)
 {
	 SetEnemyMovementStatus(EEnemyMovementStatus::EMS_MoveToTarget);

	 //Checks to make sure AI controller is valid.
	 if (AIController)
	 {

		 //Sets where the AI will move to. 
		 FAIMoveRequest MoveRequest;
		 MoveRequest.SetGoalActor(Target);
		 MoveRequest.SetAcceptanceRadius(5.0f);

		 FNavPathSharedPtr NavPath;

		 //Calls the move to function. 
		 AIController->MoveTo(MoveRequest, &NavPath);

		 UE_LOG(LogTemp, Warning, TEXT("MoveToTarget()"));
	 }

 }
