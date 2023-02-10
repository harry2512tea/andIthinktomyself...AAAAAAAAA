#include <ThomasTheTank/ThomasTheTank.h>
#include <memory>

using namespace ThomasTheTank;

struct Player : Component
{
	int lives;
	int score;
	Shared<Transform> transform;

	void onInitialize();
	void onTick();
	void onCollisionEnter(Shared<PhysB::CollisionRet> collision);
};