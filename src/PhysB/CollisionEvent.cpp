#include "CollisionEvent.h"
#include "CollisionDet.h"

namespace PhysB
{
	void CollisionEvent::physOnCollisionEnter(Shared<CollisionRet> collision)
	{}
	void CollisionEvent::physOnCollisionExit(Shared<CollisionRet> collision)
	{}
	void CollisionEvent::physOnCollisionStay(Shared<CollisionRet> collision)
	{}

	void CollisionEvent::physCollisionEnter(Shared<CollisionRet> collision)
	{
		physOnCollisionEnter(collision);
	}

	void CollisionEvent::physCollisionExit(Shared<CollisionRet> collision)
	{
		physOnCollisionExit(collision);
	}

	void CollisionEvent::physCollisionStay(Shared<CollisionRet> collision)
	{
		physOnCollisionStay(collision);
	}
	void CollisionEvent::physOnTriggerEnter(Shared<CollisionRet> collision)
	{}
	void CollisionEvent::physOnTriggerExit(Shared<CollisionRet> collision)
	{}
	void CollisionEvent::physOnTriggerStay(Shared<CollisionRet> collision)
	{}


	void CollisionEvent::physTriggerEnter(Shared<CollisionRet> collision)
	{
		physOnTriggerEnter(collision);
	}
	void CollisionEvent::physTriggerExit(Shared<CollisionRet> collision)
	{
		physOnTriggerExit(collision);
	}
	void CollisionEvent::physTriggerStay(Shared<CollisionRet> collision)
	{
		physOnTriggerStay(collision);
	}
}
