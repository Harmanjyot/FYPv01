// Fill out your copyright notice in the Description page of Project Settings.


#include "C_SackPickup.h"

// Sets default values
AC_SackPickup::AC_SackPickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AC_SackPickup::BeginPlay()
{
	Super::BeginPlay();

	
}

// Called every frame
void AC_SackPickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

