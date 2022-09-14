// Copyright Epic Games, Inc. All Rights Reserved.

#include "AllyGloriaGameMode.h"
#include "AllyGloriaHUD.h"
#include "AllyGloriaCharacter.h"

#include "UObject/ConstructorHelpers.h"


AAllyGloriaGameMode::AAllyGloriaGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AAllyGloriaHUD::StaticClass();
}
