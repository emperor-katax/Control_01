#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataTable.h"
#include "Helper.generated.h"


USTRUCT(BlueprintType)
struct FInput_Check : public FTableRowBase { // on rename the struct, restart editor
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 Damage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString Title;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStaticMesh* Default_Object_01;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite)
	//	UStaticMesh Super_Object_01; <--- not working, UStaticMesh must be pointer


	bool Check_01() {
		UE_LOG(LogTemp, Display, TEXT("ktx ####[DT]--[DT]####   Check_01 >> function/method called in C++"));
		return false;// dispatche delegate event - can get bind in BP
	};


	void Check_02() {
		UE_LOG(LogTemp, Display, TEXT("ktx ####[DT]--[DT]####   Check_02 >>  function/method called in C++"));
	};

	//UFUNCTION() // <-- error 'UFUNCTION' may only appear in Class, IInterface, and Interface scopes
	//	void myFunction();
};


UCLASS()
class CONTROL_01_API UHelper : public UObject{
	GENERATED_BODY()
};


// UObject
// https://docs.unrealengine.com/4.26/en-US/ProgrammingAndScripting/ProgrammingWithCPP/UnrealArchitecture/Objects/
// https://romeroblueprints.blogspot.com/2020/11/the-uobject-class.html
// https://ikrima.dev/ue4guide/engine-programming/uobjects/new-uobject-allocation-flow/
// https://dev.epicgames.com/community/snippets/Ele/unreal-engine-runtime-uobject-serialization

