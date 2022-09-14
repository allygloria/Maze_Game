// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "MyAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class ALLYGLORIA_API UMyAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:

	virtual void NativeInitializeAnimation() override;


	UFUNCTION(BlueprintCallable, Category = "EnemyAnimationProperties")
	void UpdateAnimationProperties();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Enemy Movement")
	float MovementSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Enemy Movement")
	class ADefaultEnemy* Enemy;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Enemy Movement")
	class APawn* Pawn;

};
