// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputMappingContext.h"
#include "InputAction.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Kismet/GameplayStatics.h"
#include "PC_A.h"
#include "Helper.h"
#include "Materials/MaterialParameterCollection.h"
#include "Materials/MaterialParameterCollectionInstance.h"
#include "Kismet/KismetMaterialLibrary.h"
#include "PlayerEnInput.h"
#include "Char_A.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FImpact_02);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDamage, float, Damage_01);


UCLASS()
class CONTROL_01_API AChar_A : public ACharacter, public IPlayerEnInput{
	GENERATED_BODY()

public:
	AChar_A();

	// input mapping data table 
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "ktx Data", meta = (AllowPrivateAccess = "true")) // <-- can be only C++
		class UDataTable* Input_DTA;

	//  delegate 
	UPROPERTY(BlueprintAssignable, Category = "ktx Player Delegate")
		FImpact_02 OnImpact;

	UPROPERTY(BlueprintAssignable, Category = "ktx Player Delegate")
		FDamage OnReciveDamageTypeA;

	UMaterialParameterCollection* MPC_A;

	void SetupValues();
	
protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	
	// ////////////////////////////// implement user input from character ++ part 1/3
	//UEnhancedInputComponent* ENHInput;
	//void ActionA_check(const FInputActionInstance& Instance);
	//void ActionB_check(const FInputActionInstance& Instance);
	//void ActionC_check(const FInputActionInstance& Instance);

	// interface support
	virtual void BP_interact_mode_B_Implementation() override; // <-- will get disabled if belonged BP event is used
	void CPP_interact_withImplementation() override; // will override base method 
	void CPP_interact_noImplementation() override; // will override base method 
	virtual void CPP_interact_mode_II_withImplementation(int ID) override; // will override base method 
	


};


// C++ Delegates
// https://docs.unrealengine.com/en-US/Programming/UnrealArchitecture/Delegates/index.html
// https://answers.unrealengine.com/questions/259969/blueprint-implementable-custom-component-events.html
// https://answers.unrealengine.com/questions/697849/creating-an-event-on-an-actorcomponent-in-c-for-bl.html
// Delegate type declarations must start with "F" character and recomended to have a "unique name"
// https://forums.unrealengine.com/t/declare-dynamic-multicast-delegate-oneparam-with-tarray/431745?mobile_view=1
// https://benui.ca/unreal/delegates-advanced/

