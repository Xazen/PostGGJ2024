// Copyright Epic Games, Inc. All Rights Reserved.

#include "PostGGJ2024GameMode.h"
#include "PostGGJ2024PlayerController.h"
#include "PostGGJ2024Character.h"
#include "UObject/ConstructorHelpers.h"

APostGGJ2024GameMode::APostGGJ2024GameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = APostGGJ2024PlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownPlayerController"));
	if(PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
}