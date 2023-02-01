#include "PhysB/Collider.h"
namespace PhysB
{

	void PhysCollider::tick()
	{
		onTick();
	}
	Plane::Plane(vec3 min, vec3 max, vec3 P2)
	{
		m_min = min;
		m_max = max;
		m_P2 = P2;

		m_normal = calculateNormal();
	}

	vec3 Plane::calculateNormal()
	{
		return normalize(cross((m_max - m_P2), (m_min - m_P2)));
	}
}