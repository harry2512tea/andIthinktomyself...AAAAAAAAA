#include "BoxCollider.h"

namespace ThomasTheTank
{
	BoxCollider::BoxCollider()
	{
		m_size = vec3(1.0f);
		m_collider = btBoxShape(m_size);
	}
}