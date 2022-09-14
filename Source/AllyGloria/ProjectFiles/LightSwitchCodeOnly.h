// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LightSwitchCodeOnly.generated.h"

class UPointLightComponent;
class USphereComponent;

UCLASS()
class ALLYGLORIA_API ALightSwitchCodeOnly : public AActor
{
	GENERATED_BODY()
	

protected:
	//Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	//Called every frame
	//virtual void Tick(float DeltaTime) override;

	//Declare point light
	UPROPERTY(VisibleAnywhere, Category = "Light Switch")
	class UPointLightComponent* PointLight;

	//Declare sphere comp **CHANGE ME to box(light switch)
	UPROPERTY(VisibleAnywhere, Category = "Light Switch")
	class USphereComponent* LightSphere;


	// Sets default values for this actor's properties
	ALightSwitchCodeOnly();

	//Light intensity
	UPROPERTY(VisibleAnywhere, Category = "Light Switch")
	float LightIntensity;

	//Overlap begin function
	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, 
	class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	//Overlap end function
	UFUNCTION()
	void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, 
	class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	//Toggle light
	UFUNCTION()
	void ToggleLight();

};
