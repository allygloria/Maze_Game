


#include "LightSwitchCodeOnly.h"
#include "Components/PointLightComponent.h"
#include "Components/SphereComponent.h"
#include "DrawDebugHelpers.h"
#include "Kismet/GameplayStatics.h"

#include "Components/BoxComponent.h"


// Sets default values
ALightSwitchCodeOnly::ALightSwitchCodeOnly()
{
	//Starting intensity, can be changed in the engine. 
	LightIntensity = 3000.0f;

	PointLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("Point Light"));
	PointLight->Intensity = LightIntensity;
	//PointLight->bVisible = true;  Commenting this part out allowed this code to work in UE 4.27 
	RootComponent = PointLight;

	//Sphere around light that acts as a trigger to turn the light off. 
	LightSphere = CreateDefaultSubobject<USphereComponent>(TEXT("Light Sphere Component"));
	LightSphere->InitSphereRadius(400.0f);
	LightSphere->SetCollisionProfileName(TEXT("Trigger"));
	LightSphere->SetupAttachment(RootComponent);

	//Calls the OnOverlapBegin and OnOverlapEnd functions. 
	LightSphere->OnComponentBeginOverlap.AddDynamic(this, &ALightSwitchCodeOnly::OnOverlapBegin);
	LightSphere->OnComponentEndOverlap.AddDynamic(this, &ALightSwitchCodeOnly::OnOverlapEnd);

}

// Called when the game starts or when spawned
void ALightSwitchCodeOnly::BeginPlay()
{
	Super::BeginPlay();

	//DrawDebugSphere(GetWorld(), GetActorLocation(), 300.0f, 50, FColor::Green, true, 999, 0, 2);
	
}

//Toggles the light on when sphere trigger is overlapped. 
void ALightSwitchCodeOnly::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor,
class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		ToggleLight();
	}
}

//Toggles the light back off when player exits the trigger sphere. 
void ALightSwitchCodeOnly::OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor,
class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		ToggleLight();
	}
}
//Toggle function, shows light visibility. 
void ALightSwitchCodeOnly::ToggleLight()
{
	PointLight->ToggleVisibility();
}