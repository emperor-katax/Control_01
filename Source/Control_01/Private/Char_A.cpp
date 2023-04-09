#include "Char_A.h"

AChar_A::AChar_A(){
 	PrimaryActorTick.bCanEverTick = true;
    // UE_LOG(LogTemp, Warning, TEXT("ktx  oo [CHAR]--[CHAR] oo   AChar_A >>   Char A - contructor"));    

    // //////////////////////////////////////////////////////////////////////////////////

    // assign data table in constructor
    static ConstructorHelpers::FObjectFinder<UDataTable> dt(TEXT("/Script/Engine.DataTable'/Game/ThirdPerson/Blueprints/DT_InputMap_01.DT_InputMap_01'"));
    
    if (dt.Succeeded()){
        Input_DTA = dt.Object;
        UE_LOG(LogTemp, Warning, TEXT("ktx  oo [CHAR]--[CHAR] oo   AChar_A >>   Data Table found"));
    }

    // //////////////////////////////////////////////////////////////////////////////////

    // assign Material Parameter Collection in constructor
    
    // FObjectFinder not working !
    //static ConstructorHelpers::FObjectFinder<UMaterialParameterCollection> objectType(TEXT("/Script/Engine.MaterialParameterCollection'/Game/ThirdPerson/Blueprints/MPC_01.MPC_01'"));
    //if (objectType.Succeeded()){ collection = objectType.Object; }
    
    // add headers <-- MUST !
    MPC_A = Cast<UMaterialParameterCollection>(StaticLoadObject(UMaterialParameterCollection::StaticClass(), nullptr, TEXT("/Script/Engine.MaterialParameterCollection'/Game/ThirdPerson/Blueprints/MPC_01.MPC_01'")));
    //UKismetMaterialLibrary::SetScalarParameterValue(GetWorld(), MPC_A, "mpc01_svar_01", 7.0); // <-- not working here in contructor!

}

void AChar_A::BeginPlay(){
	Super::BeginPlay();
}

void AChar_A::Tick(float DeltaTime){
	Super::Tick(DeltaTime);

}

void AChar_A::SetupValues() {
    UE_LOG(LogTemp, Warning, TEXT("ktx  oo [CHAR]--[CHAR] oo   AChar_A::SetupValues >>  "));
}

void AChar_A::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent){ // inherited from base class Character.h
	Super::SetupPlayerInputComponent(PlayerInputComponent);
    
    // ////////////////////////////// implement user input from character ++  part 2/3
    // get enhancedInput and player controller
    //ENHInput = Cast<UEnhancedInputComponent>(PlayerInputComponent);
    //APC_A* PC = Cast<APC_A>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
    //
    //if (PC) { 
    //    //ENHInput->BindAction(PC->Action_A, ETriggerEvent::Triggered, this, &AChar_A::ActionA_check); 
    //    //ENHInput->BindAction(PC->Action_B, ETriggerEvent::Triggered, this, &AChar_A::ActionB_check); 
    //    //ENHInput->BindAction(PC->Action_C, ETriggerEvent::Triggered, this, &AChar_A::ActionC_check); 
    //}
    //else { UE_LOG(LogTemp, Warning, TEXT("ktx  oo [CHAR]--[CHAR] oo   AChar_A >>  Undefined player controller ")); }
}


// interface support
void AChar_A::BP_interact_mode_B_Implementation(){ // <-- will get disabled if BP event is used
    UE_LOG(LogTemp, Warning, TEXT("ktx  oo [CHAR]--[CHAR] oo   AChar_A >>  BP_interact_mode_B_Implementation "));
}

void AChar_A::CPP_interact_withImplementation() {
    UE_LOG(LogTemp, Warning, TEXT("ktx     >>>>[INTFC]<<<<    AChar_A >>  CPP_interact_withImplementation "));

    OnImpact.Broadcast(); // call delegate

    // set values in material parameter collections
    UKismetMaterialLibrary::SetScalarParameterValue(GetWorld(), MPC_A, "mpc01_svar_01", 777.0);
    UKismetMaterialLibrary::SetVectorParameterValue(GetWorld(), MPC_A, "mpc01_vvar_01", FLinearColor::Blue);
}

void AChar_A::CPP_interact_noImplementation() {
    UE_LOG(LogTemp, Warning, TEXT("ktx     >>>>[INTFC]<<<<    AChar_A >>  CPP_interact_noImplementation "));

    OnImpact.Broadcast(); // call delegate

    // set values in material parameter collections
    UKismetMaterialLibrary::SetScalarParameterValue(GetWorld(), MPC_A, "mpc01_svar_01", 333.0);
    UKismetMaterialLibrary::SetVectorParameterValue(GetWorld(), MPC_A, "mpc01_vvar_01", FLinearColor::Green);
}

void AChar_A::CPP_interact_mode_II_withImplementation(int ID) {
    UE_LOG(LogTemp, Warning, TEXT("ktx     >>>>[INTFC]<<<<    AChar_A >> CPP_interact_mode_II_withImplementation recived %d as value"), ID);

    // add value to data table
    FInput_Check* InCheck = Input_DTA->FindRow<FInput_Check>(FName(TEXT("0")), "", true); // FInput_Check is my C++ data table
    if (InCheck){ // <-- always check for null
        InCheck->Damage = ID;        
        FString In_Title = InCheck->Title;
       UE_LOG(LogTemp, Warning, TEXT("ktx  oo [CHAR]--[CHAR] oo   AChar_A >> data table  - Title in data table is  %s"), *In_Title);         
        
        InCheck->Check_02(); // only C++ 
        UE_LOG(LogTemp, Warning, TEXT("ktx  oo [CHAR]--[CHAR] oo   AChar_A >> recived  %s from data table function"), (InCheck->Check_01() ? TEXT("True") : TEXT("False")));// only C++ 
        
        OnReciveDamageTypeA.Broadcast(ID); // call delegate
    }
    
    // set values in material parameter collections
    UKismetMaterialLibrary::SetScalarParameterValue(GetWorld(), MPC_A, "mpc01_svar_01", 888.0);
    UKismetMaterialLibrary::SetVectorParameterValue(GetWorld(), MPC_A, "mpc01_vvar_01", FLinearColor::MakeRandomColor());

}



// ////////////////////////////// implement user input from character ++   part 3/3
// input -->  mapping functions
//void AChar_A::ActionA_check(const FInputActionInstance& Instance) {
//    UE_LOG(LogTemp, Warning, TEXT("ktx  oo [CHAR]--[CHAR] oo   AChar_A::ActionA_check >>         A"));
//    
//}

//void AChar_A::ActionB_check(const FInputActionInstance& Instance) { // E key
//    UE_LOG(LogTemp, Warning, TEXT("ktx  oo [CHAR]--[CHAR] oo   AChar_A::ActionB_check >>  B "));
//    
//    // get value from input
//    float input_Value = Instance.GetValue().Get<float>();
//    UE_LOG(LogTemp, Warning, TEXT("ktx    %f "), input_Value);
//
//    // add value to data table
//    FInput_Check* InCheck = Input_DTA->FindRow<FInput_Check>(FName(TEXT("0")), "", true);
//    if (InCheck){ // <-- always check for null
//        FString In_Title = InCheck->Title;
//        InCheck->Damage = input_Value;
//        UE_LOG(LogTemp, Warning, TEXT("ktx  oo [CHAR]--[CHAR] oo   AChar_A >> data table  - Title .... %s"), *In_Title);
//        
//        OnReciveDamageTypeA.Broadcast(input_Value); // call delegate
//    }
//}

//void AChar_A::ActionC_check(const FInputActionInstance& Instance) { // Q key
//    UE_LOG(LogTemp, Warning, TEXT("ktx  oo [CHAR]--[CHAR] oo   AChar_A::ActionC_check >>    C "));
//
//    bool BoolValue = Instance.GetValue().Get<bool>();
//    UE_LOG(LogTemp, Warning, TEXT("ktx    %s"), (BoolValue ? TEXT("True") : TEXT("False")));
//    
//    OnImpact.Broadcast(); // call delegate
//}



// UE_LOG notes
// UE_LOG(LogTemp, Warning, TEXT("Text, %d %f %s"), intVar, floatVar, *fstringVar );
// UE_LOG(YourLog,Warning,TEXT("MyCharacter's Bool is %s"), (MyCharacter->MyBool ? TEXT("True") : TEXT("False")));
// UE_LOG(YourLog,Warning,TEXT("MyCharacter's Location is %s"), *MyCharacter->GetActorLocation().ToString());
// https://www.chrismccole.com/blog/logging-in-ue4-cpp

