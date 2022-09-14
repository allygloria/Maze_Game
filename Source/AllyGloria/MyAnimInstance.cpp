// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAnimInstance.h"
#include "DefaultEnemy.h"


void  UMyAnimInstance::NativeInitializeAnimation()
{
	//Checks to make sure the pawn is valid
	if (Pawn == nullptr)
	{
		Pawn = TryGetPawnOwner();

		if (Pawn)
		{
			Enemy = Cast<ADefaultEnemy>(Pawn);
		}
	}
}

void UMyAnimInstance::UpdateAnimationProperties()
{
	//Checks to make sure the pawn is valid
	if (Pawn == nullptr)
	{
		Pawn = TryGetPawnOwner();

		if (Pawn)
		{
		
			Enemy = Cast<ADefaultEnemy>(Pawn);
		}

	}
	if (Pawn)
	{
		//Speed updated
		FVector Speed = Pawn->GetVelocity();
		FVector LateralSpeed = FVector(Speed.X, Speed.Y, 0.f);
		MovementSpeed = LateralSpeed.Size();
	}
}