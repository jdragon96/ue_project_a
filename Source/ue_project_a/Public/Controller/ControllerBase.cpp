#include "Controller/ControllerBase.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/PawnMovementComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "InputAction.h"
#include "InputMappingContext.h"
#include "InputModifiers.h"
#include "PlayerAnimation.h"
#include "PlayerCharacter.h"

AControllerBase::AControllerBase() {
	bShowMouseCursor = false;
	PlayerContext = NewObject<UInputMappingContext>();
}
void AControllerBase::BeginPlay() {
	Super::BeginPlay();
	// 1. Input Mapping Context?? ????
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if (Subsystem) {
		Subsystem->AddMappingContext(PlayerContext, 0);
	}

	// 2. ???²J ??? o??
	bShowMouseCursor = false;
	DefaultMouseCursor = EMouseCursor::Default;
	FInputModeGameOnly InputMode;
	SetInputMode(InputMode);

	// 3. ???? ?????? u?
	OwnerActor = GetPawn<APlayerCharacter>();
	OwnerAnimation = Cast<UPlayerAnimation>(OwnerActor->GetMesh()->GetAnimInstance());

	// 4. ¾×¼Ç »ý¼º
	InitAction();
}
void AControllerBase::SetupInputComponent() {
	Super::SetupInputComponent();
	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);
	BindAction(EnhancedInputComponent);
}
void AControllerBase::PreProcessInput(const float DeltaTime, const bool bGamePaused) {
	Super::PreProcessInput(DeltaTime, bGamePaused);
	MoveVector.X = 0.0;
	MoveVector.Y = 0.0;
	MoveVector.Z = 0.0;
	ClearInputState();
}
void AControllerBase::PostProcessInput(const float DeltaTime,const bool bGamePaused) {
	Super::PostProcessInput(DeltaTime, bGamePaused);
	UpdateInputState();
}
void AControllerBase::InitAction()
{
}
void AControllerBase::BindAction(UEnhancedInputComponent* Component)
{
}
void AControllerBase::ClearInputState() {

}
void AControllerBase::UpdateInputState() {
}