// Fill out your copyright notice in the Description page of Project Settings.


#include "SkillSphereCollisionDetection.h"
#include "Components/SphereComponent.h"
#include "SkillBase.h"

// Sets default values
ASkillSphereCollisionDetection::ASkillSphereCollisionDetection()
{
	// Set this actor to call Tick() every frame
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>("Root");
	SphereDetectionMesh = CreateDefaultSubobject<USphereComponent>("DetectionMesh");

	if (SphereDetectionMesh != nullptr && RootComponent != nullptr)
		SphereDetectionMesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ASkillSphereCollisionDetection::BeginPlay()
{
	Super::BeginPlay();

	if (SphereDetectionMesh != nullptr)
	{
		SphereDetectionMesh->OnComponentBeginOverlap.AddUniqueDynamic(this, &ASkillSphereCollisionDetection::TriggerBeginOverlap);
		SphereDetectionMesh->OnComponentEndOverlap.AddUniqueDynamic(this, &ASkillSphereCollisionDetection::TriggerEndOverlap);
	}

}

// Called every frame
void ASkillSphereCollisionDetection::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASkillSphereCollisionDetection::Init(USkillBase* _skillOwner)
{
	skillOwner = _skillOwner;

	if (skillOwner == nullptr)
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("SkillSphereCollisionDetection::Init :: NO SKILL OWNER")));
}

void ASkillSphereCollisionDetection::TriggerBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (skillOwner != nullptr)
	{
		skillOwner->DetectionMeshBeginOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
	}
}

void ASkillSphereCollisionDetection::TriggerEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (skillOwner != nullptr)
		skillOwner->DetectionMeshEndOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex);
}