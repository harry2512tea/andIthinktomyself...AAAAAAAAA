#include "CollisionDet.h"
#include "Collider.h"
#include "PhysRigidBody.h"
#include "PhysTransform.h"
#include "Collisions.h"

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
			Colliders.at(i)->tick();
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
		Potentials.clear();
		for (size_t C1 = 0; C1 < Colliders.size(); C1++)
		{
			for (size_t C2 = C1 + 1; C2 < Colliders.size(); C2++)
			{
				if (!Colliders.at(C1)->isTrigger || !Colliders.at(C2)->isTrigger)
				{
					if (broadCollisionDetection(Colliders.at(C1), Colliders.at(C2)))
					{
						Potentials.push_back(CollisionPair(Colliders.at(C1), Colliders.at(C2)));
					}
				}
			}
		}

		for (size_t I = 0; I < Potentials.size(); I++)
		{
			if (narrowCollisionDetection(Potentials.at(I).Col1, Potentials.at(I).Col1))
			{
				Collision.push_back(Potentials.at(I).Col1);
				Collision.push_back(Potentials.at(I).Col2);
			}
		}
	}
	bool CollisionDet::broadCollisionDetection(Shared<PhysCollider> Col1, Shared<PhysCollider> Col2)
	{
		vec3 Col1Max = Col1->getMax();
		vec3 Col1Min = Col1->getMin();
		vec3 Col2Max = Col2->getMax();
		vec3 Col2Min = Col2->getMin();

		if ((Col1Min.x <= Col2Max.x && Col1Max.x <= Col2Min.x) &&
			(Col1Min.y <= Col2Max.y && Col1Max.y <= Col2Min.y) &&
			(Col1Min.z <= Col2Max.z && Col1Max.z <= Col2Min.z))
		{
			return true;
		}
		else
		{
			return false;
		}

		
		return false;
	}
	bool CollisionDet::narrowCollisionDetection(Shared<PhysCollider> Col1, Shared<PhysCollider> Col2)
	{
		return false;
	}



	CollisionPair::CollisionPair(Shared<PhysCollider> _Col1, Shared<PhysCollider> _Col2)
	{
		Col1 = _Col1;
		Col2 = _Col2;
	}
}
