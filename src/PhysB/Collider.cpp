#include "PhysB/Collider.h"
#include "PhysB/PhysTransform.h"
namespace PhysB
{
	void PhysCollider::setSize(vec3 _size)
	{
		size = _size;
		m_min = m_initialMin * _size;
		m_max = m_initialMax * _size;
	}
	void PhysCollider::addRigidBody(Shared<PhysRigidBody> _body)
	{
		m_RigidBody = _body;
		isDynamic = true;
	}

	void PhysCollider::removeRigidBody()
	{
		m_RigidBody = Weak<PhysRigidBody>();
		isDynamic = false;
	}

	void PhysCollider::tick()
	{
		m_min = (m_initialMin * size) + m_trans->getPosition();
		m_max = (m_initialMax * size) + m_trans->getPosition();
		onTick();
	}

	Plane::Plane( vec3 _max, vec3 _min, vec3 _P2)
	{
		m_min = _min;
		m_max = _max;
		m_P2 = _P2;

		min = m_min;
		max = m_max;
		C = m_P2;
		UpdatePos(vec3(0.0f));
		m_normal = calculateNormal();
	}

	void Plane::UpdatePos(vec3 newPos, vec3 scale)
	{
		min = m_min * scale + newPos;
		max = m_max * scale + newPos;
		C = m_P2 * scale + newPos;
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