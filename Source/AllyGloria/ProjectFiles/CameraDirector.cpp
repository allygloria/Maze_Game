// Ally Gloria GAM312 3/12/2022
//Camera System Director


#include "CameraDirector.h"
#include "Kismet/GameplayStatics.h"



// Sets default values
ACameraDirector::ACameraDirector()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACameraDirector::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACameraDirector::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Time it takes to move between cameras.
	const float TimeBetweenCameraChange = 2.0f;

	//Time it takes to smoothly blend between cameras.
	const float SmoothBlendTime = 0.75f;

	TimeToNextCameraChange -= DeltaTime;

	if (TimeToNextCameraChange <= 0.0f)
	{
		TimeToNextCameraChange += TimeBetweenCameraChange;

		//Get the first player controller that is found. 
		APlayerController* OurPlayerController = UGameplayStatics::GetPlayerController(this, 0);
		if (OurPlayerController)
		{
			//If CameraTwo exists and the current camera is CameraOne blend to CameraTwo.
			if (CameraTwo && (OurPlayerController->GetViewTarget() == CameraOne))
			{
				//Smoothly blends to CameraTwo
				OurPlayerController->SetViewTargetWithBlend(CameraTwo, SmoothBlendTime);
			}
			//If CameraThree exists and the current camera is CameraTwo, blend to CameraThree.
			else if (CameraThree && (OurPlayerController->GetViewTarget() == CameraTwo))
			{
				//Smoothly blends to CameraThree.
				OurPlayerController->SetViewTargetWithBlend(CameraThree, SmoothBlendTime);
			}
			else if (CameraOne)
			{
				//Go to camera one instantly. 
				OurPlayerController->SetViewTarget(CameraOne);
			}
		}
	}
	
}

