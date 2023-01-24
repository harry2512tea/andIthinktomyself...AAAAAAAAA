#include "../../Wrapping/ThomasMath.h"
#include "../Collider.h"
#include <memory>

#define Shared std::shared_ptr
#define Weak std::weak_ptr

namespace ThomasTheTank
{
	struct Transform;

	struct BoxCollider : Collider
	{

	protected:
		Weak<Transform> m_Transform;
		//vec3 m_rotation;
	};
}