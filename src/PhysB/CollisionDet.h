#ifndef PHYSB_COLLISIONDET_H
#define PHYSB_COLLISIONDET_H

#include <memory>
#include <vector>
//#include <glm/glm.hpp>
#include "GLMWrapping.h"

#define Shared std::shared_ptr
#define Weak std::weak_ptr
#define mkShared std::make_shared

namespace PhysB
{
	struct PhysCollider;

	struct PhysTransform;

	struct PhysRigidBody;

	struct PhysicsWorld;

	struct CollisionDet
	{
		void Tick();

		void AddCollider(Shared<PhysCollider> _col);
		Shared<PhysTransform> AddTransform();
		Shared<PhysRigidBody> AddRigidBody(Shared<PhysTransform> _trans);
		Shared<PhysicsWorld> getPhysicsWorld() { return m_Phys.lock(); };
		void runCollisionDetection();

	private:
		std::vector<Shared<PhysRigidBody>> RigidBodies;
		std::vector <Shared<PhysCollider>> Colliders;
		std::vector <Shared<PhysTransform>> Transforms;
		Weak<CollisionDet> m_self;
		Weak<PhysicsWorld> m_Phys;
	};
}
#endif