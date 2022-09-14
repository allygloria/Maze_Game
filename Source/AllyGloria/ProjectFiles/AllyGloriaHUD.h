// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "AllyGloriaHUD.generated.h"

UCLASS()
class AAllyGloriaHUD : public AHUD
{
	GENERATED_BODY()

public:
	AAllyGloriaHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

