#include "Physics.h"

namespace ThomasTheTank
{
	Physics::Physics() :
		dispatcher(&collisionConfiguration),
		dynamicsWorld(std::make_shared<btDiscreteDynamicsWorld>(&dispatcher, &overlappingPairCache, &solver, &collisionConfiguration))
	{

	}

	void Physics::addCollider(Shared<btCollisionShape> _shape)
	{
		collisionShapes.push_back(_shape);
	}
}