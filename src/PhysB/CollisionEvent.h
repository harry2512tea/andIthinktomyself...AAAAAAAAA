#ifndef PHYSB_COLLISIONEVENT_H
#define PHYSB_COLLISIONEVENT_H

#include <memory>

#define Shared std::shared_ptr
#define Weak std::weak_ptr
#define mkShared std::make_shared

namespace PhysB
{
	struct CollisionDet;
	struct Collisions;
	struct CollisionRet;

	struct CollisionEvent
	{
	private:
		friend struct CollisionDet;
		virtual void physOnCollisionEnter(Shared<CollisionRet> collision);
		virtual void physOnCollisionExit(Shared<CollisionRet> collision);
		virtual void physOnCollisionStay(Shared<CollisionRet> collision);
		void physCollisionEnter(Shared<CollisionRet> collision);
		void physCollisionExit(Shared<CollisionRet> collision);
		void physCollisionStay(Shared<CollisionRet> collision);

		virtual void physOnTriggerEnter(Shared<CollisionRet> collision);
		virtual void physOnTriggerExit(Shared<CollisionRet> collision);
		virtual void physOnTriggerStay(Shared<CollisionRet> collision);
		void physTriggerEnter(Shared<CollisionRet> collision);
		void physTriggerExit(Shared<CollisionRet> collision);
		void physTriggerStay(Shared<CollisionRet> collision);
	};

}
#endif