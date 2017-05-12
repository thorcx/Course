#include "UECourse.h"
#include "BoomProjectile.h"


ABoomProjectile::ABoomProjectile()
{
	SphereCollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("BallCollision1"));

	RootComponent = SphereCollisionComponent;

	//�����SetCollisionProfileName��Ӧ����ProjectSetting->Collision->Preset�µ�ProfileName
	//�����ڱ༭����Ӻ�Profile��Ȼ���ڴ����е������ã�ע�⹹�캯���ڲ�������Profile�����캯��ִ�е�ʱ��
	//Profile��δ������ϣ���������ÿ��Էŵ�PostInitializeComponents()��

	//SphereCollisionComponent->SetCollisionProfileName("BlockAllDynamic");

	//����ObjectType
	SphereCollisionComponent->SetCollisionObjectType(ECC_WorldDynamic);
	
	//����չʾ����[C10 ppt13]�е��Զ�����ײͨ��
	//SphereCollisionComponent->SetCollisionObjectType(COLLISION_BOOM);
	

	//����Collision Enabled
	SphereCollisionComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	//����Response
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



//������Simulate��㿪���忴����
void ABoomProjectile::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	//����Profile�Ḳ�ǵ����湹�캯��ָ����������ײ����
	//��������ͼ�����ѡ��preset,�������Զ�������ָ����һ������
	//SphereCollisionComponent->SetCollisionProfileName("BlockAllDynamic");
	SphereCollisionComponent->OnComponentBeginOverlap.AddDynamic(this, &ABoomProjectile::OnProjectileBeginOverlap);
	
}

void ABoomProjectile::OnProjectileBeginOverlap_Implementation(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult)
{
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Red, TEXT("boom!"));
}
