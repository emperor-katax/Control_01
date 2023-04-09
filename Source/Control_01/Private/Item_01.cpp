#include "Item_01.h"

AItem_01::AItem_01(){
 	PrimaryActorTick.bCanEverTick = true;
}

void AItem_01::BeginPlay(){
	Super::BeginPlay();
	//UE_LOG(LogTemp, Warning, TEXT("ktx ---- AItem_01 >>  "));
	
}

void AItem_01::Tick(float DeltaTime){
	Super::Tick(DeltaTime);

}


// UE_LOG notes
// UE_LOG(LogTemp, Warning, TEXT("Text, %d %f %s"), intVar, floatVar, *fstringVar );
// UE_LOG(YourLog,Warning,TEXT("MyCharacter's Bool is %s"), (MyCharacter->MyBool ? TEXT("True") : TEXT("False")));
// UE_LOG(YourLog,Warning,TEXT("MyCharacter's Location is %s"), *MyCharacter->GetActorLocation().ToString());
// https://www.chrismccole.com/blog/logging-in-ue4-cpp



