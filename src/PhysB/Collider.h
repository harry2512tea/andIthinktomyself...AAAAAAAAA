#ifndef PHYSB_COLLIDER_H
#define PHYSB_COLLIDER_H

#include <memory>
#include <vector>
#include <glm/glm.hpp>

#define Shared std::shared_ptr
#define Weak std::weak_ptr
#define mkShared std::make_shared

namespace PhysB
{
	struct CollisionDet;

	struct PhysTransform;
	enum ColType
	{
		Box,
		Sphere
	};

	struct PhysCollider
	{
		virtual void onTick();
		void tick();
		glm::vec3 offset;
		glm::vec3 rotation;
		ColType getType() { return colliderType; };

	protected:
		friend struct PhysicsWorld;
		ColType colliderType;
		Weak<PhysCollider> m_self;
		Weak<CollisionDet> m_ColDet;
		Shared<PhysTransform> m_trans;
	};
}

#endif