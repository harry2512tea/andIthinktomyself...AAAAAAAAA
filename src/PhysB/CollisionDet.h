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

	struct Plane;

	struct CollisionPair
	{
		CollisionPair(Shared<PhysCollider> _Col1, Shared<PhysCollider> _Col2);
		Shared<PhysCollider> Col1, Col2;
	};

	struct CollisionInfo
	{
		vec3 point;
		vec3 normal;
		Shared<PhysCollider> Col1, Col2;
		bool colliding;
	private:
		friend struct CollisionDet;
		friend struct Collisions;
		Shared<PhysCollider> ColliderPlane, ColliderToMove;
		vec3 collidingPoint;
		Weak<Plane> CollisionPlane;
	};

	struct CollisionDet
	{
		void Tick();

		void AddCollider(Shared<PhysCollider> _col);
		Shared<PhysTransform> AddTransform();
		Shared<PhysRigidBody> AddRigidBody(Shared<PhysTransform> _trans);
		Shared<PhysicsWorld> getPhysicsWorld() { return m_Phys.lock(); };
		void runCollisionDetection();

	private:
		friend struct PhysicsWorld;
		bool broadCollisionDetection(Shared<PhysCollider> Col1, Shared<PhysCollider> Col2);
		Shared<CollisionInfo> narrowCollisionDetection(Shared<PhysCollider> Col1, Shared<PhysCollider> Col2);
		void collisionResponse(Shared<CollisionInfo> colInfo);
		std::vector<Shared<PhysRigidBody>> RigidBodies;
		std::vector <Shared<PhysCollider>> Colliders;
		std::vector <Shared<PhysTransform>> Transforms;
		std::vector <CollisionPair> Potentials;
		std::vector <Shared<CollisionInfo>> Collision;
		Weak<CollisionDet> m_self;
		Weak<PhysicsWorld> m_Phys;
		Shared<Collisions> m_collisions;
	};
}
#endif