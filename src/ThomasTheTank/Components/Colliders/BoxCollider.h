#include "../../Wrapping/ThomasMath.h"
#include "../Collider.h"

namespace ThomasTheTank
{
	struct BoxCollider : Collider
	{
		BoxCollider();

	protected:
		vec3 m_size;
		//vec3 m_rotation;
	};
}