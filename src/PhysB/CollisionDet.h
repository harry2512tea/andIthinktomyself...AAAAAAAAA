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

	struct Collisions;

	struct CollisionPair
	{
		CollisionPair(Shared<PhysCollider> _Col1, Shared<PhysCollider> _Col2);
		Shared<PhysCollider> Col1, Col2;
	};

	struct CollisionInfo
	{
		vec3 point;
		Shared<PhysCollider> Col1, Col2;
		bool colliding;
	};

	struct CollisionDet
	{
		void Tick();

		void AddCollider(Shared<PhysCollider> _col);
		Shared<PhysTransform> AddTransform();
		Shared<PhysRigidBody> AddRigidBody(Shared<PhysTransform> _trans);
		Shared<PhysicsWorld> getPhysicsWorld() { return m_Phys.lock(); };
		void runCollisionDetection();
		bool broadCollisionDetection(Shared<PhysCollider> Col1, Shared<PhysCollider> Col2);
		bool narrowCollisionDetection(Shared<PhysCollider> Col1, Shared<PhysCollider> Col2);

	private:
		friend struct PhysicsWorld;
		std::vector<Shared<PhysRigidBody>> RigidBodies;
		std::vector <Shared<PhysCollider>> Colliders;
		std::vector <Shared<PhysTransform>> Transforms;
		std::vector <CollisionPair> Potentials;
		std::vector <Shared<PhysCollider>> Collision;
		Weak<CollisionDet> m_self;
		Weak<PhysicsWorld> m_Phys;
		Shared<Collisions> m_collisions;
	};
}
#endif