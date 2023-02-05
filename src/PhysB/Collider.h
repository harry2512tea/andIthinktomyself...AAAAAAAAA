#ifndef PHYSB_COLLIDER_H
#define PHYSB_COLLIDER_H

#include <memory>
#include <vector>
//#include <glm/glm.hpp>
#include "GLMWrapping.h"

#define Shared std::shared_ptr
#define Weak std::weak_ptr
#define mkShared std::make_shared

namespace PhysB
{
	struct CollisionDet;

	struct PhysTransform;

	struct PhysRigidBody;

	struct CollisionEvent;

	enum ColType
	{
		Box,
		Sphere
	};

	struct Ray
	{
		Ray(vec3 _Direction, vec3 _Origin);
		vec3 getDirection() { return Direction; };
		vec3 getOrigin() { return Origin; };
	private:
		vec3 Direction, Origin;
	};

	struct Plane
	{
		Plane( vec3 max, vec3 min, vec3 P2);
		vec3 getNormal() { return m_normal; };
		void UpdatePos(vec3 newPos);
		bool getIntersect(Shared<Ray> _ray, vec3& Intersect);
	protected:
		vec3 m_min, m_P2, m_max, m_normal;
		vec3 min, max, C;
		vec3 calculateNormal();
	};

	struct PhysCollider
	{
		
		glm::vec3 offset;
		glm::vec3 rotation;
		ColType getType() { return colliderType; };
		vec3 getMin() { return m_min; };
		vec3 getMax() { return m_max; };
		vec3 getSize() { return (m_max - m_min)/2.0f; };
		void setMin(vec3(_min)) { m_min = _min; };
		void setMax(vec3(_max)) { m_max = _max; };
		void setEventHandler(Shared< CollisionEvent> _event) { m_eventHandler = _event; };

		Shared<PhysTransform> Transform() { return m_trans; };
		int getID() { return ID; };

	private:
		vec3 m_initialMin = vec3(-0.5f), m_initialMax = vec3(0.5f);
		vec3 m_min = vec3(-0.5f), m_max = vec3(0.5f);
		int ID;
	protected:
		friend struct PhysicsWorld;
		friend struct CollisionDet;
		friend struct Collisions;
		virtual void onTick() {};
		void tick();
		ColType colliderType;
		bool isDynamic = false;
		bool isTrigger = false;

		Weak<CollisionEvent> m_eventHandler;
		Weak<PhysCollider> m_self;
		Weak<PhysRigidBody> m_RigidBody;
		Weak<CollisionDet> m_ColDet;
		Shared<PhysTransform> m_trans;
	};
}

#endif