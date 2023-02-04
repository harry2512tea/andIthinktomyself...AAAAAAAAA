#include "CollisionEvent.h"

namespace PhysB
{
	void PhysB::CollisionEvent::physOnCollisionEnter(Shared<CollisionInfo> collision)
	{}
	void CollisionEvent::physOnCollisionExit(Shared<CollisionInfo> collision)
	{}
	void CollisionEvent::physOnCollisionStay(Shared<CollisionInfo> collision)
	{}

	void CollisionEvent::physCollisionEnter(Shared<CollisionInfo> collision)
	{
		physOnCollisionEnter(collision);
	}

	void CollisionEvent::physCollisionExit(Shared<CollisionInfo> collision)
	{
		physOnCollisionExit(collision);
	}

	void CollisionEvent::physCollisionStay(Shared<CollisionInfo> collision)
	{
		physOnCollisionStay(collision);
	}
}
