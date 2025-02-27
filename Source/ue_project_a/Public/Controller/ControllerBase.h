#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ControllerBase.generated.h"

class UInputAction;
struct FInputActionValue;
class UInputMappingContext;
class UQuaterViewIMC;
class APlayerCharacter;
class UPlayerAnimation;
class UEnhancedInputComponent;

/**
 *
 */
UCLASS()
class UE_PROJECT_A_API AControllerBase : public APlayerController {
  GENERATED_BODY()

public:
  AControllerBase();

protected:
  virtual void BeginPlay() override;
  virtual void SetupInputComponent() override;
  virtual void PreProcessInput(const float DeltaTime,
                               const bool bGamePaused) override;
  virtual void PostProcessInput(const float DeltaTime,
                                const bool bGamePaused) override;
  /// <summary>
  /// 액션 초기화, 생성자에서 호출
  /// </summary>
  virtual void InitAction();

  /// <summary>
  /// 액션 콜백함수 연결, SetupInputComponent에서 호출
  /// </summary>
  virtual void BindAction(UEnhancedInputComponent* Component);

  /// <summary>
  /// 입력 상태 초기화, PreProcessInput에서 호출
  /// </summary>
  virtual void ClearInputState();

  /// <summary>
  /// 입력 상태 업데이트, PostProcessInput에서 호출
  /// </summary>
  virtual void UpdateInputState();

public:
  /// <summary>
  /// ĳ???? ??? ??????
  /// </summary>
  UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Movement")
  FVector MoveVector;

  /// <summary>
  /// 
  /// </summary>
  UPROPERTY(EditAnywhere, Category = "Movement")
  double TransitionRate = 0.2;

protected:
  /// <summary>
  /// 
  /// </summary>
  TObjectPtr<UInputMappingContext> PlayerContext;

  /// <summary>
  /// ĳ????, ??????? ?ν???? ??????
  /// </summary>
  TObjectPtr<APlayerCharacter> OwnerActor;

  /// <summary>
  /// 
  /// </summary>
  TObjectPtr<UPlayerAnimation> OwnerAnimation;

private:
};
