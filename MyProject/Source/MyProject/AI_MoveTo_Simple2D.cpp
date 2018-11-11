// Fill out your copyright notice in the Description page of Project Settings.

#include "AI_MoveTo_Simple2D.h"

UAI_MoveTo_Simple2D::UAI_MoveTo_Simple2D(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer), WorldContextObject(nullptr), MyFloatInput(0.0f) {

}

UAI_MoveTo_Simple2D* UAI_MoveTo_Simple2D::WaitForOneFrame(UObject* WorldContextObject, const float SomeInputVariables) {
	UAI_MoveTo_Simple2D* BlueprintNode = NewObject<UAI_MoveTo_Simple2D>();
	BlueprintNode->WorldContextObject = WorldContextObject;
	BlueprintNode->MyFloatInput = SomeInputVariables;
	return BlueprintNode;
}

void UAI_MoveTo_Simple2D::Activate() {
	// Any safety checks should be performed here. Check here validity of all your pointers etc.
	// You can log any errors using FFrame::KismetExecutionMessage, like that:
	// FFrame::KismetExecutionMessage(TEXT("Valid Player Controller reference is needed for ... to start!"), ELogVerbosity::Error); // return;

	WorldContextObject->GetWorld()->GetTimerManager().SetTimerForNextTick(this, &UAI_MoveTo_Simple2D::ExecuteAfterOneFrame);
}

void UAI_MoveTo_Simple2D::ExecuteAfterOneFrame() {
	AfterOneFrame.Broadcast(MyFloatInput + 1.0f, MyFloatInput + 2.0f);
}