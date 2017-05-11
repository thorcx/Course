// Fill out your copyright notice in the Description page of Project Settings.

#include "UECourse.h"
#include "GameCommon.h"
#include "FlyBase.h"


// Sets default values
AFlyBase::AFlyBase()
	:CurrentForwardSpeed(0.f)
	,BoostFactor(100.f)
{

	BodyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BodyMesh"));

	ConstructorHelpers::FObjectFinder<UStaticMesh> meshAsset(TEXT("StaticMesh'/Game/Assets/C05/SM_UFO.SM_UFO'"));
	if (meshAsset.Object)
	{
		BodyMesh->SetStaticMesh(meshAsset.Object);
	}
	RootComponent = BodyMesh;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SprintArm0"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->TargetArmLength = 300.0f;
	SpringArm->SocketOffset = FVector(0.f, 0.f, 60.f);
	SpringArm->bEnableCameraLag = false;
	
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera0"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
	Camera->bUsePawnControlRotation = false;
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bUseControllerRotationYaw = true;
	bUseControllerRotationPitch = true;
}

// Called when the game starts or when spawned
void AFlyBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFlyBase::Tick(float DeltaTime)
{
	FVector LocalMove = FVector(CurrentForwardSpeed * DeltaTime, CurrentFlankSpeed * DeltaTime, CurrentVerticalSpeed * DeltaTime);
	LocalMove *= BoostFactor;
	AddActorLocalOffset(LocalMove, true);
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFlyBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	check(PlayerInputComponent);
	//PlayerInputComponent->BindAxis("MoveForward",	this,	&AFlyBase::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight",     this,   &AFlyBase::MoveRight);
	PlayerInputComponent->BindAxis("MoveUp",        this,   &AFlyBase::MoveUp);

	//注意这里可以直接绑定到APawn的父类函数上去
	PlayerInputComponent->BindAxis("Turn",			this,	&APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp",        this,   &APawn::AddControllerPitchInput);
	
	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &AFlyBase::Fire);
	
	//首先直观的在这里声明
	//然后放到GameCommon里去，因为其他的类有可能用到这个映射
	//FInputAxisKeyMapping backKey("Back", EKeys::S, -1.0f);
	//FInputAxisKeyMapping forwardKey("Back", EKeys::W, 1.0f);
	GetWorld()->GetFirstPlayerController()->PlayerInput->AddAxisMapping(GameGlobal::backKey);
	GetWorld()->GetFirstPlayerController()->PlayerInput->AddAxisMapping(GameGlobal::forwardKey);
	
	//注意这里如果不小心填错了要绑定的动作名称，编译期间不会报错，执行期函数不会被回调执行，特别注意如果绑定完了不执行检查名称拼写
	PlayerInputComponent->BindAxis("CodeMoveForward", this, &AFlyBase::MoveForward);
	//Super::SetupPlayerInputComponent(PlayerInputComponent);

}
//前进后退
void AFlyBase::MoveForward(float val)
{
	CurrentForwardSpeed += val;
	CurrentForwardSpeed = FMath::Clamp(CurrentForwardSpeed, -500.f, 500.f);
	//AddMovementInput(GetActorForwardVector(), val);
}
//作为作业
void AFlyBase::MoveRight(float val)
{
	CurrentFlankSpeed += val;
	CurrentFlankSpeed = FMath::Clamp(CurrentFlankSpeed, -200.f, 200.f);

}
//作业
void AFlyBase::MoveUp(float val)
{
	CurrentVerticalSpeed += val;
	CurrentVerticalSpeed = FMath::Clamp(CurrentVerticalSpeed, -300.f, 300.f);
}

void AFlyBase::Fire()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Booooo~~~~"));
	if (BulletClass)
	{
		UWorld *world = GetWorld();
		if (world)
		{
			//这里用到一种方法来获得子弹初始的位置
			//作业再实现一种方式来定义子弹的初始位置
			//利用你自己的实现方式，实现双管发射，双管同时发射，轮流发射
			FTransform spawnTrans = BodyMesh->GetSocketTransform("GunSocket");
			FActorSpawnParameters param;
			world->SpawnActor(BulletClass, &spawnTrans);
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No Bullet Type Specified!!!"));
	}
}

