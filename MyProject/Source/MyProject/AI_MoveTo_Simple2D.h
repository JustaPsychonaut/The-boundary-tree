// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//#include "CoreMinimal.h"
#include "Engine.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "AI_MoveTo_Simple2D.generated.h"

/**
 * 
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FAI_MoveTo_Simple2DOutputPin, float, InputFloatPlusOne, float, InputFloatPlusTwo);

UCLASS()
class MYPROJECT_API UAI_MoveTo_Simple2D : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public: 
	UAI_MoveTo_Simple2D(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(BlueprintAssignable) 
	FAI_MoveTo_Simple2DOutputPin AfterOneFrame;

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "Flow Control")
	static UAI_MoveTo_Simple2D* WaitForOneFrame(UObject* WorldContextObject, const float SomeInputVariables);

	//UBlueprintAsyncActionBase interface
	virtual void Activate() override;

	//~UBlueprintAsyncActionBase interface
private:
	UFUNCTION()
	void ExecuteAfterOneFrame();

private:
	UObject * WorldContextObject;
	float MyFloatInput;
};