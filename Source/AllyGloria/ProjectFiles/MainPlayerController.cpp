// Fill out your copyright notice in the Description page of Project Settings.


#include "MainPlayerController.h"
#include "Blueprint/UserWidget.h"

void AMainPlayerController::BeginPlay()
{
	Super::BeginPlay();

	//Creates the HUD widget
	if (Overlay_HUDAsset)
	{
		Overlay_HUD = CreateWidget<UUserWidget>(this, Overlay_HUDAsset);
	}

	//Adds the HUD to the viewport.
	Overlay_HUD->AddToViewport();

	//Makes the HUD to be set as visible. 
	Overlay_HUD->SetVisibility(ESlateVisibility::Visible);

	//Adding the pause menu to the veiwport
	if (WPauseMenu)
	{
		PauseMenu = CreateWidget<UUserWidget>(this, WPauseMenu);
		if (PauseMenu)
		{
			PauseMenu->AddToViewport();
			PauseMenu->SetVisibility(ESlateVisibility::Hidden);
		}
	}
}
//If pause menu key is pressed, the menu is visible. 
void AMainPlayerController::DisplayPauseMenu_Implementation()
{
	if (PauseMenu)
	{
		bPauseMenuVisible = true;
		PauseMenu->SetVisibility(ESlateVisibility::Visible);


		//When pause menu is visible, player can can interact with UI.
		//Will still be able to toggle the menu on and off screen. 
		FInputModeGameAndUI InputModeGameAndUI;
		SetInputMode(InputModeGameAndUI);

		//Shows mouse cursor in UI
		bShowMouseCursor = true;
	}
}

//When the pause menu key is not being pressed, the menu is hidden. 
void AMainPlayerController::RemovePauseMenu_Implementation()
{

	FInputModeGameOnly InputModeGameOnly;
	SetInputMode(InputModeGameOnly);

	//Toggles the mouse off.
	bShowMouseCursor = false;

	bPauseMenuVisible = false;

}

void  AMainPlayerController::TogglePauseMenu()
{
	if (bPauseMenuVisible)
	{
		RemovePauseMenu();
	}
	else
	{
		DisplayPauseMenu();
	}
}