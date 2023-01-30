#include "PhysRigidBody.h"
#include "PhysTransform.h"
#include "CollisionDet.h"
#include "Physics.h"

namespace PhysB
{
	void PhysRigidBody::AddForce(glm::vec3 force, ForceMode _mode)
	{
		switch (_mode)
		{
		case PhysB::Impulse:
			velocity += force / mass;
			break;
		case PhysB::VelocityChange:
			velocity += force;
			break;
		}
	}

	void PhysRigidBody::tick()
	{
		Shared<PhysTransform> trans = m_trans.lock();
		trans->Translate(velocity);
		trans->Rotate(angularVelocity);
		if (gravity)
		{
			velocity += m_colDet.lock()->getPhysicsWorld()->getGravity();
		}
	}
}