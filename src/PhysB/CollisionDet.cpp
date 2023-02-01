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
		if (!_trans->dynamic)
		{
			Shared<PhysRigidBody> temp = std::make_shared<PhysRigidBody>();
			temp->m_trans = _trans;
			temp->m_colDet = m_self.lock();
			RigidBodies.push_back(temp);
			return temp;
		}
		else
		{
			return _trans->m_body.lock();
		}
	}
	void CollisionDet::runCollisionDetection()
	{
		for (size_t C1 = 0; C1 < Colliders.size(); C1++)
		{
			for (size_t C2 = C1 + 1; C2 < Colliders.size(); C2++)
			{
				if (!Colliders.at(C1)->isTrigger || !Colliders.at(C2)->isTrigger)
				{
					if (Colliders.at(C1)->m_trans->dynamic || Colliders.at(C2)->m_trans->dynamic)
					{
						dynamicCollisionDetection(Colliders.at(C1), Colliders.at(C2));
					}
					else
					{
						staticCollisionDetection(Colliders.at(C1), Colliders.at(C2));
					}
				}
			}
		}
	}
	bool CollisionDet::dynamicCollisionDetection(Shared<PhysCollider> Col1, Shared<PhysCollider> Col2)
	{
		return false;
	}
	bool CollisionDet::staticCollisionDetection(Shared<PhysCollider> Col1, Shared<PhysCollider> Col2)
	{
		return false;
	}
}
