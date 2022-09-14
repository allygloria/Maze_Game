//Pickup helps the player, could be a coin or possibly health. 


#include "Pickup.h"
#include "AllyGloriaCharacter.h"

APickup::APickup()
{

}

void APickup::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::OnOverlapBegin(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);

	UE_LOG(LogTemp, Warning, TEXT("Pickup::OnOverlapBegin"));

	if (OtherActor)
	{
		AAllyGloriaCharacter* AllyGloriaCharacter = Cast<AAllyGloriaCharacter>(OtherActor);

		if (AllyGloriaCharacter)
		{
			//Player picks up coins. 
			AllyGloriaCharacter->IncreaseCoins(CoinCount);
		}
	}
}

void APickup::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	Super::OnOverlapEnd(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex);

	UE_LOG(LogTemp, Warning, TEXT("Pickup::OnOverlapEnd"));
}