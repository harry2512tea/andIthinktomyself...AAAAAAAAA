#include <ThomasTheTank/ThomasTheTank.h>

using namespace ThomasTheTank;

struct Asteroid : Component
{
	Shared<Transform> transform;
	Shared<RigidBody> body;
	Shared<MeshRenderer> renderer;
	Shared<Model> model;
	Shared<Texture> texture;
	vec3 originalPos;
	vec3 dir;

	void onInitialize();
	void onTick();
	void onCollisionEnter(Shared<PhysB::CollisionRet> collision);
};