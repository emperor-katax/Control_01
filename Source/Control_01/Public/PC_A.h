#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InputMappingContext.h"
#include "InputAction.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "PlayerEnInput.h"
#include "PC_A.generated.h"

/**
 * 
 */
UCLASS()
class CONTROL_01_API APC_A : public APlayerController{
	GENERATED_BODY()



public:

	APC_A(); // custom constructor - not exist by default

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "ktx Enhanced Input", meta = (AllowPrivateAccess = "true"))
		class UInputMappingContext* inputMapping;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "ktx Enhanced Input", meta = (AllowPrivateAccess = "true"))
		class UInputAction* Action_A;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "ktx Enhanced Input", meta = (AllowPrivateAccess = "true"))
		class UInputAction* Action_B;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "ktx Enhanced Input", meta = (AllowPrivateAccess = "true"))
		class UInputAction* Action_C;

	UFUNCTION(BlueprintCallable, Category = "Item 01")
		void SetupValues();


private:
	UEnhancedInputComponent* ENHInput;
	void ActionA_check(const FInputActionInstance& Instance);
	void ActionB_check(const FInputActionInstance& Instance);
	void ActionC_check(const FInputActionInstance& Instance);
	
};


// property referncing
// https://docs.unrealengine.com/5.1/en-US/referencing-assets-in-unreal-engine/

