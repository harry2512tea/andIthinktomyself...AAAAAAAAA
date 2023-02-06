#include "CollisionEvent.h"

namespace PhysB
{
	void CollisionEvent::physOnCollisionEnter(Shared<CollisionInfo> collision)
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
	void CollisionEvent::physOnTriggerEnter(Shared<CollisionInfo> collision)
	{}
	void CollisionEvent::physOnTriggerExit(Shared<CollisionInfo> collision)
	{}
	void CollisionEvent::physOnTriggerStay(Shared<CollisionInfo> collision)
	{}


	void CollisionEvent::physTriggerEnter(Shared<CollisionInfo> collision)
	{
		physOnTriggerEnter(collision);
	}
	void CollisionEvent::physTriggerExit(Shared<CollisionInfo> collision)
	{
		physOnTriggerExit(collision);
	}
	void CollisionEvent::physTriggerStay(Shared<CollisionInfo> collision)
	{
		physOnTriggerStay(collision);
	}
}
