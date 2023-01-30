#include "CollisionDet.h"
#include "Collider.h"
#include "PhysRigidBody.h"
#include "PhysTransform.h"

#include <iostream>

namespace PhysB
{
	void CollisionDet::Tick()
	{
		std::cout << "Collision Detect Tick" << std::endl;
		runCollisionDetection();
		for (size_t i = 0; i < RigidBodies.size(); i++)
		{
			RigidBodies.at(i)->tick();
		}
		for (size_t i = 0; i < Colliders.size(); i++)
		{

		}
		for (size_t i = 0; i < Transforms.size(); i++)
		{
			Transforms.at(i)->Tick();
		}
			
	}

	void CollisionDet::AddCollider(Shared<PhysCollider> _col)
	{
		Colliders.push_back(_col);
	}

	Shared<PhysTransform> CollisionDet::AddTransform()
	{
		Shared<PhysTransform> _trans = mkShared<PhysTransform>();
		Transforms.push_back(_trans);
		return _trans;
	}

	Shared<PhysRigidBody> CollisionDet::AddRigidBody(Shared<PhysTransform> _trans)
	{
		Shared<PhysRigidBody> temp = std::make_shared<PhysRigidBody>();
		temp->m_trans = _trans;
		temp->m_colDet = m_self.lock();
		RigidBodies.push_back(temp);
		return temp;
	}
	void CollisionDet::runCollisionDetection()
	{
	}
}
