// Fill out your copyright notice in the Description page of Project Settings.


#include "MainItem.h"

// Sets default values
AMainItem::AMainItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>("Scene");
	itemMesh = CreateDefaultSubobject<UStaticMeshComponent>("ItemMesh");

	if (itemMesh != nullptr && RootComponent != nullptr)
	{
		itemMesh->SetupAttachment(RootComponent);
	}
}

// Called when the game starts or when spawned
void AMainItem::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMainItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

