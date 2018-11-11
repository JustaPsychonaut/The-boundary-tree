// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AI_RelocationConnectionPoints.generated.h"

UCLASS()
class MYPROJECT_API AAI_RelocationConnectionPoints : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAI_RelocationConnectionPoints();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	UFUNCTION(CallInEditor)
	void Deploy();

	UFUNCTION(CallInEditor)
	void Reset();

	UPROPERTY(VisibleDefaultsOnly)
	class UTextRenderComponent* Left;

	UPROPERTY(VisibleDefaultsOnly)
	class UTextRenderComponent* Right;

	UPROPERTY()
	class USplineComponent* Spline;

};