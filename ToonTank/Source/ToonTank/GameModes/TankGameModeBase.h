// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
//Incluide Steam API
#include "ToonTank/Steam/steam_api.h"
#include "TankGameModeBase.generated.h"
//Definition ID
#define RAW_APP_ID "480"


class APawnTurret;
class APawnTank;
class APlayerControllerBase;
UCLASS()
class TOONTANK_API ATankGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
private:


	APawnTank* PlayerTank;
	int32 TargetTurrets = 0;
	APlayerControllerBase* PlayerControllerRef;

	int32 GetTargetTurretCount();

	void HandleGameStart();
	void HandleGameOver(bool PlayerWon);

public:

	void ActorDie(AActor* DeadActor);

	static constexpr char* APP_ID = RAW_APP_ID;
	CSteamID MyId;

protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Game Loop")
	int32 StartDelay = 3;


	virtual void BeginPlay() override;
	UFUNCTION(BlueprintImplementableEvent)
	void GameStart();
	UFUNCTION(BlueprintImplementableEvent)
	void GameOver(bool PlayerWon);
};
