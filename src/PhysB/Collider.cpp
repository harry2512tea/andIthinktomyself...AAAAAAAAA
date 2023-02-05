#include "PhysB/Collider.h"
#include "PhysB/PhysTransform.h"
namespace PhysB
{

	void PhysCollider::tick()
	{
		m_min = m_initialMin + m_trans->getPosition();
		m_max = m_initialMax + m_trans->getPosition();
		onTick();
	}

	Plane::Plane( vec3 max, vec3 min, vec3 P2)
	{
		m_min = min;
		m_max = max;
		m_P2 = P2;

		m_normal = calculateNormal();
	}

	void Plane::UpdatePos(vec3 newPos)
	{
		min = m_min + newPos;
		max = m_max + newPos;
		C = m_P2 + newPos;
		m_normal = calculateNormal();
	}

	bool Plane::getIntersect(Shared<Ray> _ray, vec3& Intersect)
	{
		float d = dot(m_normal, max);

		if (dot(m_normal, _ray->getDirection()) != 0)
		{
			float x = (d - dot(m_normal, _ray->getOrigin())) / dot(m_normal, _ray->getDirection());
			Intersect = _ray->getOrigin() + (_ray->getDirection() * x);
			return true;
		}
		else
		{
			return false;
		}

	}

	vec3 Plane::calculateNormal()
	{
		return normalize(cross((m_max - m_P2), (m_min - m_P2)));
	}

	Ray::Ray(vec3 _Direction, vec3 _Origin)
	{
		Direction = _Direction;
		Origin = _Origin;
	}
}