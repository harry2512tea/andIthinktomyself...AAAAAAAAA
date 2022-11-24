#include "../../Wrapping/ThomasMath.h"
#include "../Collider.h"
#include <pellet/btBulletDynamicsCommon.h>
#include <memory>

#define Shared std::shared_ptr

namespace ThomasTheTank
{
	struct BoxCollider : Collider
	{
		BoxCollider();

	protected:
		vec3 m_size = vec3(1.0f);
		Shared<btBoxShape> m_collider;
		btTransform trans;
		Shared<btDefaultMotionState> m_MotionState;
		Shared<btRigidBody> body;
		//vec3 m_rotation;
	};
}