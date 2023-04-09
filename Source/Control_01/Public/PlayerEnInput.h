#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "PlayerEnInput.generated.h"

UINTERFACE(MinimalAPI)
class UPlayerEnInput : public UInterface{
	GENERATED_BODY()
};


class CONTROL_01_API IPlayerEnInput{
	GENERATED_IINTERFACE_BODY()

	public:
		// BP interface
		UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "ktx Enhanced Input Interface")
			const int BP_interact_mode_A(); // type

		UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "ktx Enhanced Input Interface")
			void BP_interact_mode_B(); // none type

		UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "ktx Enhanced Input Interface")
			void BP_interact_mode_I(int& ID); // signature

		UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "ktx Enhanced Input Interface")
			void BP_interact_mode_II(int ID); // signature


		// C++ interface	
		virtual void CPP_interact_withImplementation(); // virtual, can be override
		void CPP_interact_withImplementation_Base(); // none virtual, public
		
		// no Implementation becuase this is an abstract method ... MUST be override if inhirited 
		virtual void CPP_interact_noImplementation() = 0; // abstract, MUST be override in child class

		virtual void CPP_interact_mode_II_withImplementation(int ID); // virtual, can be override

};
