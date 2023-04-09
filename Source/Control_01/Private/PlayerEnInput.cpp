#include "PlayerEnInput.h"

void IPlayerEnInput::CPP_interact_withImplementation(){
	UE_LOG(LogTemp, Warning, TEXT("ktx	   +++[INTFC]+++     -- IPlayerEnInput >>  CPP_interact_withImplementation "));
}

void IPlayerEnInput::CPP_interact_withImplementation_Base() {
	UE_LOG(LogTemp, Warning, TEXT("ktx	   +++[INTFC]+++     -- IPlayerEnInput >>  CPP_interact_withImplementation Only_Base "));
}

void IPlayerEnInput::CPP_interact_mode_II_withImplementation(int ID){
	UE_LOG(LogTemp, Warning, TEXT("ktx	   +++[INTFC]+++     -- IPlayerEnInput >> CPP_interact_mode_II_withImplementation %d is recived"), ID);
}

