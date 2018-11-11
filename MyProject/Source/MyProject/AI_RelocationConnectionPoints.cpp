// Fill out your copyright notice in the Description page of Project Settings.

#include "AI_RelocationConnectionPoints.h"
#include "Engine.h"
#include <Runtime/Engine/Classes/Components/SplineComponent.h>


// Sets default values
AAI_RelocationConnectionPoints::AAI_RelocationConnectionPoints()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	SetFolderPath("AIAssistance");

	class USceneComponent* SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = SceneComponent;

	Left = CreateDefaultSubobject<UTextRenderComponent>(TEXT("Left"));
	Left->SetupAttachment(RootComponent);
	Left->bEditableWhenInherited = true;
	Left->SetRelativeRotation(FRotator(0.f, 90.f, 0.f).Quaternion());
	Left->SetHorizontalAlignment(EHTA_Center);
	Left->SetVerticalAlignment(EVRTA_TextCenter);
	Left->SetText(TEXT("POINT"));
	Left->SetTextRenderColor(FColor::Green);

	Right = CreateDefaultSubobject<UTextRenderComponent>(TEXT("Right"));
	Right->SetupAttachment(RootComponent);
	Right->bEditableWhenInherited = true;
	Right->SetRelativeRotation(FRotator(0.f, 90.f, 0.f).Quaternion());
	Right->SetHorizontalAlignment(EHTA_Center);
	Right->SetVerticalAlignment(EVRTA_TextCenter);
	Right->SetText(TEXT("POINT"));
	Right->SetTextRenderColor(FColor::Green);

	Spline = CreateDefaultSubobject<USplineComponent>(TEXT("DebugLine"));
	Spline->SetupAttachment(RootComponent);
	for (int i = 0; Spline->GetNumberOfSplinePoints() < 2; i++) {
		Spline->AddPoint(FSplinePoint((float)i, FVector(0.f)));
	}
	Spline->EditorSelectedSplineSegmentColor = FColor::Green;
	Spline->EditorUnselectedSplineSegmentColor = FColor::Green;
	Spline->SetVisibility(false);

}

// Called when the game starts or when spawned
void AAI_RelocationConnectionPoints::BeginPlay()
{
	Super::BeginPlay();
	
}

void AAI_RelocationConnectionPoints::Deploy() {

	if (!GEngine) return;
	
	if (!Spline || !Spline->IsValidLowLevel()) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, FString("Error. No spline detected"));
		return;
	}

	if (!Left || !Left->IsValidLowLevel() || !Right || !Right->IsValidLowLevel()) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, FString("Error. Point(s) is(are) missing"));
		return;
	}

	TArray<FVector> points = {
		Left->GetComponentLocation(),
		Right->GetComponentLocation()
	};
	Spline->SetSplinePoints(points, ESplineCoordinateSpace::World);
	Spline->SetVisibility(true);

	Left->SetVisibility(false);
	Right->SetVisibility(false);

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, UKismetSystemLibrary::GetDisplayName(this) + FString(" is deployed"));

}

void AAI_RelocationConnectionPoints::Reset() {

	if (!GEngine) return;

	if (!Spline || !Spline->IsValidLowLevel()) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, FString("Error. No spline detected"));
		return;
	}

	if (!Left || !Left->IsValidLowLevel() || !Right || !Right->IsValidLowLevel()) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, FString("Error. Point(s) is(are) missing"));
		return;
	}

	Spline->SetVisibility(false);

	Left->SetVisibility(true);
	Right->SetVisibility(true);

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, UKismetSystemLibrary::GetDisplayName(this) + FString(" is reset"));

}