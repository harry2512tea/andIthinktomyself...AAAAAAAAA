#include "CollisionDet.h"
#include "Collider.h"
#include "PhysRigidBody.h"
#include "PhysTransform.h"
#include "Collisions.h"
#include "CollisionEvent.h"

#include <iostream>

namespace PhysB
{
	void CollisionDet::Tick()
	{
		//std::cout << "Collision Detect Tick" << std::endl;
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
						std::cout << "Broad Collision True" << std::endl;
						Potentials.push_back(CollisionPair(Colliders.at(C1), Colliders.at(C2)));
					}
				}
			}
		}

		for (size_t I = 0; I < Potentials.size(); I++)
		{
			Shared<CollisionInfo> col = narrowCollisionDetection(Potentials.at(I).Col1, Potentials.at(I).Col2);
			if (col->colliding)
			{
				std::cout << "Narrow Collision True" << std::endl;
				Collision.push_back(col);
				col->Col1->m_eventHandler.lock()->physCollisionEnter(col);
				std::cout << col->point.x << " " << col->point.y << " " << col->point.z << std::endl;
			}
		}
	}
	bool CollisionDet::broadCollisionDetection(Shared<PhysCollider> Col1, Shared<PhysCollider> Col2)
	{
		/*vec3 Col1Max = Col1->getMax();
		vec3 Col1Min = Col1->getMin();
		vec3 Col2Max = Col2->getMax();
		vec3 Col2Min = Col2->getMin();*/

		vec3 Col1S = Col1->getSize();
		vec3 Col2S = Col2->getSize();
		vec3 Col1Pos = Col1->m_trans->getPosition();
		vec3 Col2Pos = Col2->m_trans->getPosition();

		if (Col1Pos.x > Col2Pos.x)
		{
			if (Col1Pos.x - Col1S.x > Col2Pos.x + Col2S.x)
			{
				return false;
			}
		}
		else
		{
			if (Col2Pos.x - Col2S.x > Col1Pos.x + Col1S.x)
			{
				return false;
			}
		}

		if (Col1Pos.z > Col2Pos.z)
		{
			if (Col1Pos.z - Col1S.z > Col2Pos.z + Col2S.z)
			{
				return false;
			}
		}
		else
		{
			if (Col2Pos.z - Col2S.z > Col1Pos.z + Col1S.z)
			{
				return false;
			}
		}

		if (Col1Pos.y > Col2Pos.y)
		{
			if (Col1Pos.y - Col1S.y > Col2Pos.y + Col2S.y)
			{
				return false;
			}
		}
		else
		{
			if (Col2Pos.y - Col2S.y > Col1Pos.y + Col1S.y)
			{
				return false;
			}
		}

		return true;

		/*if ((Col1Min.x <= Col2Max.x && Col1Min.x >= Col2Max.x) &&
			(Col1Min.y <= Col2Max.y && Col1Min.y >= Col2Max.y) &&
			(Col1Min.z <= Col2Max.z && Col1Min.z >= Col2Max.z))
		{
			return true;
		}
		else
		{
			return false;
		}*/
	}

	Shared<CollisionInfo> CollisionDet::narrowCollisionDetection(Shared<PhysCollider> Col1, Shared<PhysCollider> Col2)
	{

		Shared<CollisionInfo> temp = m_collisions->CheckCollision(Col1, Col2);

		return temp;
	}



	CollisionPair::CollisionPair(Shared<PhysCollider> _Col1, Shared<PhysCollider> _Col2)
	{
		Col1 = _Col1;
		Col2 = _Col2;
	}
}
