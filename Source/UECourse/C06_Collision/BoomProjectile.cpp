#include "UECourse.h"
#include "BoomProjectile.h"


ABoomProjectile::ABoomProjectile()
{
	SphereCollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("BallCollision1"));

	RootComponent = SphereCollisionComponent;

	//这里的SetCollisionProfileName对应的是ProjectSetting->Collision->Preset下的ProfileName
	//可以在编辑器里加好Profile，然后在代码中调用设置，注意构造函数内不能设置Profile，构造函数执行的时候
	//Profile尚未加载完毕，如果想设置可以放到PostInitializeComponents()中

	//SphereCollisionComponent->SetCollisionProfileName("BlockAllDynamic");

	//设置ObjectType
	SphereCollisionComponent->SetCollisionObjectType(ECC_WorldDynamic);
	
	//这里展示的是[C10 ppt13]中的自定义碰撞通道
	//SphereCollisionComponent->SetCollisionObjectType(COLLISION_BOOM);
	

	//设置Collision Enabled
	SphereCollisionComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	//设置Response
	SphereCollisionComponent->SetCollisionResponseToChannel(ECC_Pawn, ECR_Ignore);
	SphereCollisionComponent->bGenerateOverlapEvents = 1;

	BoomMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BoomMesh"));
	ConstructorHelpers::FObjectFinder<UStaticMesh> meshAsset(TEXT("StaticMesh'/Game/Assets/C06/Cone_Brush2_StaticMesh.Cone_Brush2_StaticMesh'"));
	if (meshAsset.Object)
	{
		BoomMeshComponent->SetStaticMesh(meshAsset.Object);
	}
	BoomMeshComponent->SetupAttachment(SphereCollisionComponent);
	BoomMeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	
	ProjectileMoveComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
	ProjectileMoveComponent->InitialSpeed = 1000;
	ProjectileMoveComponent->MaxSpeed = 15000;


}



//这里用Simulate后点开物体看属性
void ABoomProjectile::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	//设置Profile会覆盖掉上面构造函数指定的其他碰撞属性
	//就如在蓝图内如果选了preset,其他属性都不让你指定了一个道理
	//SphereCollisionComponent->SetCollisionProfileName("BlockAllDynamic");
	SphereCollisionComponent->OnComponentBeginOverlap.AddDynamic(this, &ABoomProjectile::OnProjectileBeginOverlap);
	
}

void ABoomProjectile::OnProjectileBeginOverlap_Implementation(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult)
{
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Red, TEXT("boom!"));
}
