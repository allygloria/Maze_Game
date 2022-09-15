// Fill out your copyright notice in the Description page of Project Settings.


#include "TagController.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Runtime/Engine/Classes/Engine/TargetPoint.h"

//Sets new beginplay function. 
void ATagController::BeginPlay()
{
	Super::BeginPlay();

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATargetPoint::StaticClass(), Waypoints);

	//AI goes to a random way point. 
	GoToRandomWaypoint();
}
//Gets a random waypoint location.
ATargetPoint* ATagController::GetRandomWaypoint()
{
	auto index = FMath::RandRange(0, Waypoints.Num() - 1);
	return Cast<ATargetPoint>(Waypoints[index]);
}

//Moves to the waypoint. 
void ATagController::GoToRandomWaypoint()
{
	MoveToActor(GetRandomWaypoint());
}
//Once move is completed, move to next waypoint.
//Delay one second before moving to next waypoint. 
void ATagController::OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result)
{
	Super::OnMoveCompleted(RequestID, Result);

	GetWorldTimerManager().SetTimer(TimerHandle, this, &ATagController::GoToRandomWaypoint, 1.0f, false);
}
