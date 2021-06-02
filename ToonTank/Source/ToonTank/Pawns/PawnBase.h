// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/CapsuleComponent.h"
#include "ToonTank/Actors/ProjectileBase.h"
#include "Kismet/GameplayStatics.h"
#include "PawnBase.generated.h"


class UCapsuleComponent;
class AProjectileBase;
class UHealthComponent;

UCLASS()
class TOONTANK_API APawnBase : public APawn
{
	GENERATED_BODY()

private:
	//COMPONENTS
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "True"))
	UCapsuleComponent* CapsuleComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "True"))
	UStaticMeshComponent* BaseMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "True"))
	UStaticMeshComponent* TurretMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "True"))
	USceneComponent* ProjectileSpawnPoint; 
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UHealthComponent* HealthComponent;

	//VARIABLES
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Projectiles Type", meta = (AllowPrivateAccess = "True"))
	TSubclassOf<AProjectileBase> ProjectileClass;

	UPROPERTY(EditAnywhere, Category = "Effects")
	UParticleSystem* DeathParticle;
	UPROPERTY(EditAnywhere, Category = "Effects")
	USoundBase* DeathSound;
	UPROPERTY(EditAnywhere, Category = "Effects")
	TSubclassOf<UCameraShake> DeathShake;




public:
	// Sets default values for this pawn's properties
	APawnBase();

	void PawnDestoyed();

	virtual void HandleDestruction();

protected:

	virtual void RotateTurret(FVector LookAtTarget);

	virtual	void Fire();

	



};
