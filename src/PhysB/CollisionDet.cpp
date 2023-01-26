#include "CollisionDet.h"
#include "Collider.h"
#include "PhysRigidBody.h"
#include "PhysTransform.h"

namespace PhysB
{
	void CollisionDet::Tick()
	{
	}

	void CollisionDet::AddCollider(Shared<Collider> _col)
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
		RigidBodies.push_back(temp);
		return temp;
	}
}
