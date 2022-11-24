#include "../../Wrapping/ThomasMath.h"
#include "../Collider.h"
#include <pellet/btBulletDynamicsCommon.h>

namespace ThomasTheTank
{
	struct BoxCollider : Collider
	{
		BoxCollider();

	protected:
		vec3 m_size;
		btBoxShape m_collider;
		//vec3 m_rotation;
	};
}