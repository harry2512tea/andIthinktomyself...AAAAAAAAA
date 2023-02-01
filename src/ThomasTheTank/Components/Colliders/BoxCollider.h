#ifndef THOMASTHETANK_BOXCOLLIDER_H
#define THOMASTHETANK_BOXCOLLIDER_H

#include "../../Wrapping/ThomasMath.h"
#include "../Collider.h"
#include <memory>
#include <PhysB/PhysB.h>

#define Shared std::shared_ptr
#define Weak std::weak_ptr

namespace ThomasTheTank
{
	struct Transform;

	struct BoxCollider : Collider
	{

	protected:
		void onInitialize();
		void onTick();
		Weak<Transform> m_Transform;
		Weak<PhysB::PhysAABB> m_collider;
		//vec3 m_rotation;
	};
}
#endif // !THOMASTHETANK_BOXCOLLIDER_H