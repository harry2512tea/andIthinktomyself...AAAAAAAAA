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
	struct CollisionInfo;

	struct CollisionEvent
	{
	private:
		friend struct CollisionDet;
		virtual void physOnCollisionEnter(Shared<CollisionInfo> collision);
		virtual void physOnCollisionExit(Shared<CollisionInfo> collision);
		virtual void physOnCollisionStay(Shared<CollisionInfo> collision);
		void physCollisionEnter(Shared<CollisionInfo> collision);
		void physCollisionExit(Shared<CollisionInfo> collision);
		void physCollisionStay(Shared<CollisionInfo> collision);
	};

}
#endif