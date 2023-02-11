#include <ThomasTheTank/ThomasTheTank.h>
#include <memory>

using namespace ThomasTheTank;

struct Player : Component
{
	int lives;
	int score;
	Shared<Transform> transform;
	Shared<BoxCollider> col;
	Shared<MeshRenderer> renderer;
	Shared<Model> model;
	Shared<Texture> texture;
	Shared<AudioClip> explosionClip;
	Shared<AudioClip> engineClip;
	Shared<AudioSource> explosionSource;
	Shared<AudioSource> engineSource;

	void onInitialize();
	void onTick();
	void onCollisionEnter(Shared<PhysB::CollisionRet> collision);
};