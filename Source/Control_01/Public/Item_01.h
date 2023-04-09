#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item_01.generated.h"

UCLASS()
class CONTROL_01_API AItem_01 : public AActor{
	GENERATED_BODY()
	
public:	
	AItem_01();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

};
