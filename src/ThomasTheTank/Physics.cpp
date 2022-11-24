#include "Physics.h"

namespace ThomasTheTank
{
	Physics::Physics() :
		dispatcher(&collisionConfiguration),
		dynamicsWorld(std::make_shared<btDiscreteDynamicsWorld>(&dispatcher, &overlappingPairCache, &solver, &collisionConfiguration))
	{

	}
}