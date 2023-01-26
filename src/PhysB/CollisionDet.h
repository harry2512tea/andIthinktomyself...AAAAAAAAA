#ifndef PHYSB_COLLISIONDET_H
#define PHYSB_COLLISIONDET_H

#include <memory>
#include <vector>
#include <glm/glm.hpp>

#define Shared std::shared_ptr
#define Weak std::weak_ptr
#define mkShared std::make_shared

namespace PhysB
{
	struct Collider;

	struct PhysTransform;

	struct PhysRigidBody;

	struct Physics;

	struct CollisionDet
	{
		void Tick();

		void AddCollider(Shared<Collider> _col);
		Shared<PhysTransform> AddTransform();
		Shared<PhysRigidBody> AddRigidBody(Shared<PhysTransform> _trans);

	private:
		std::vector<Shared<PhysRigidBody>> RigidBodies;
		std::vector <Shared<Collider>> Colliders;
		std::vector <Shared<PhysTransform>> Transforms;
		Weak<CollisionDet> m_self;
		Weak<Physics> m_Phys;
	};
}
#endif