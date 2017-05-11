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

	//ע���������ֱ�Ӱ󶨵�APawn�ĸ��ຯ����ȥ
	PlayerInputComponent->BindAxis("Turn",			this,	&APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp",        this,   &APawn::AddControllerPitchInput);
	
	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &AFlyBase::Fire);
	
	//����ֱ�۵�����������
	//Ȼ��ŵ�GameCommon��ȥ����Ϊ���������п����õ����ӳ��
	//FInputAxisKeyMapping backKey("Back", EKeys::S, -1.0f);
	//FInputAxisKeyMapping forwardKey("Back", EKeys::W, 1.0f);
	GetWorld()->GetFirstPlayerController()->PlayerInput->AddAxisMapping(GameGlobal::backKey);
	GetWorld()->GetFirstPlayerController()->PlayerInput->AddAxisMapping(GameGlobal::forwardKey);
	
	//ע�����������С�������Ҫ�󶨵Ķ������ƣ������ڼ䲻�ᱨ��ִ���ں������ᱻ�ص�ִ�У��ر�ע����������˲�ִ�м������ƴд
	PlayerInputComponent->BindAxis("CodeMoveForward", this, &AFlyBase::MoveForward);
	//Super::SetupPlayerInputComponent(PlayerInputComponent);

}
//ǰ������
void AFlyBase::MoveForward(float val)
{
	CurrentForwardSpeed += val;
	CurrentForwardSpeed = FMath::Clamp(CurrentForwardSpeed, -500.f, 500.f);
	//AddMovementInput(GetActorForwardVector(), val);
}
//��Ϊ��ҵ
void AFlyBase::MoveRight(float val)
{
	CurrentFlankSpeed += val;
	CurrentFlankSpeed = FMath::Clamp(CurrentFlankSpeed, -200.f, 200.f);

}
//��ҵ
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
			//�����õ�һ�ַ���������ӵ���ʼ��λ��
			//��ҵ��ʵ��һ�ַ�ʽ�������ӵ��ĳ�ʼλ��
			//�������Լ���ʵ�ַ�ʽ��ʵ��˫�ܷ��䣬˫��ͬʱ���䣬��������
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

