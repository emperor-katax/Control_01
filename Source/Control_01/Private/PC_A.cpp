#include "PC_A.h"

APC_A::APC_A() { // custom constructor - not exist by default
    PrimaryActorTick.bCanEverTick = true;
    UE_LOG(LogTemp, Log, TEXT("ktx --[PC]--[PC]--   APC_A  constructor >>  "));
}


void APC_A::SetupValues() {
    UE_LOG(LogTemp, Log, TEXT("ktx --[APC_A]--   SetupValues >>  "));
    
    // Get the local player enhanced input subsystem
    UEnhancedInputLocalPlayerSubsystem* ENHSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(this->GetLocalPlayer());
    ENHSubsystem->AddMappingContext(inputMapping, 0);
    
    //ENHInput = Cast<UEnhancedInputComponent>(GetPawn()->GetController()->InputComponent); // same like next line
    ENHInput = Cast<UEnhancedInputComponent>(InputComponent); // grab input component
    if (ENHInput) {
        ENHInput->BindAction(Action_A, ETriggerEvent::Triggered, this, &APC_A::ActionA_check);
        ENHInput->BindAction(Action_B, ETriggerEvent::Triggered, this, &APC_A::ActionB_check);
        ENHInput->BindAction(Action_C, ETriggerEvent::Triggered, this, &APC_A::ActionC_check);
    }else{
        UE_LOG(LogTemp, Log, TEXT("ktx --[PC]--[PC]--   APC_A >>  Undefined input component "));
    }

}

// Inject input 
// https://dev.epicgames.com/community/snippets/XVP/unreal-engine-simulate-player-input-with-enhanced-input


 // input -->  mapping functions
void APC_A::ActionA_check(const FInputActionInstance& Instance) {
    UE_LOG(LogTemp, Log, TEXT("ktx --[APC_A]--   ActionA_check >>         A"));

}

void APC_A::ActionB_check(const FInputActionInstance& Instance) { // E key
    //UE_LOG(LogTemp, Warning, TEXT("	ktx --[APC_A]--   ActionB_check >>  B "));

    // get value from input
    float input_Value = Instance.GetValue().Get<float>();
    UE_LOG(LogTemp, Log, TEXT("ktx --[APC_A]--   ActionB_check >>    %f  recived by E key"), input_Value);

    //if (GetLocalPlayer()->GetClass()->ImplementsInterface(UPlayerEnInput::StaticClass())) { // <-- not working !
    if (GetPawn()->GetClass()->ImplementsInterface(UPlayerEnInput::StaticClass())) {
        UE_LOG(LogTemp, Error, TEXT("ktx --[APC_A]--   ActionB_check >> interface call BP "));
        // BP interface call
        IPlayerEnInput::Execute_BP_interact_mode_B(GetPawn());
        IPlayerEnInput::Execute_BP_interact_mode_II(GetPawn(), input_Value / 2); // 700 / 2 
        UE_LOG(LogTemp, Error, TEXT("ktx --[APC_A]--   ActionB_check >> interface call C++ "));
        // CPP interface call 
        IPlayerEnInput* ReactingObject = Cast<IPlayerEnInput>(GetPawn());
        ReactingObject->CPP_interact_mode_II_withImplementation(input_Value * -1); // 700 * -1
        
        // interface access
        // https://docs.unrealengine.com/4.26/en-US/ProgrammingAndScripting/GameplayArchitecture/Interfaces/

    } else {
        UE_LOG(LogTemp, Log, TEXT("ktx --[APC_A]--   ActionB_check >>  >> no interface <<  "));
    }


}
void APC_A::ActionC_check(const FInputActionInstance& Instance) { // Q key
    UE_LOG(LogTemp, Log, TEXT("ktx --[APC_A]--   ActionC_check >>    C "));

    bool BoolValue = Instance.GetValue().Get<bool>(); // recived bool value
    UE_LOG(LogTemp, Log, TEXT("ktx --[APC_A]--   ActionC_check >>  %s  recived by Q key"), (BoolValue ? TEXT("True") : TEXT("False")))
    if (GetPawn()->GetClass()->ImplementsInterface(UPlayerEnInput::StaticClass())) {
        // CPP interface call
        UE_LOG(LogTemp, Error, TEXT("ktx --[APC_A]--   ActionC_check >> interface call C++ "));
        IPlayerEnInput* ReactingObject = Cast<IPlayerEnInput>(GetPawn());
        ReactingObject->CPP_interact_withImplementation();
        ReactingObject->CPP_interact_noImplementation();
        ReactingObject->CPP_interact_withImplementation_Base();
    }
    else {
        UE_LOG(LogTemp, Log, TEXT("ktx --[APC_A]--   ActionC_check >>  >> no interface <<  "));
    }
}