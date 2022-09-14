// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Runtime/Engine/Classes/Engine/TargetPoint.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

#include "TagController.generated.h"


UCLASS()
class ALLYGLORIA_API ATagController : public AAIController
{
	GENERATED_BODY()

public:
   virtual void BeginPlay() override;

    //Does something once the move is completed
    void OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result) override;
private:

    FTimerHandle TimerHandle;
    
    //Storing all of the waypoints. 
    UPROPERTY()
        TArray<AActor*> Waypoints;

    UFUNCTION()
        ATargetPoint* GetRandomWaypoint();

    UFUNCTION()
        void GoToRandomWaypoint();

};
