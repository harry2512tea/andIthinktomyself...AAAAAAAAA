#include "BoxCollider.h"
#include "ThomasTheTank/Core.h"
#include "ThomasTheTank/Physics.h"
#include "ThomasTheTank/Entity.h"
#include "ThomasTheTank/Components/Transform.h"

namespace ThomasTheTank
{
	BoxCollider::BoxCollider() :
		m_collider(std::make_shared<btBoxShape>(btVector3(m_size.x, m_size.y, m_size.z))),
		m_MotionState(std::make_shared<btDefaultMotionState>(btDefaultMotionState(trans)))
	{
		getCore()->getPhysics()->addCollider(m_collider);

		trans.setIdentity();
		vec3 pos = getEntity()->getTransform()->getPosition();
		trans.setOrigin(btVector3(pos.x, pos.y, pos.z));


		btScalar mass(0.0f);

		bool isDynamic = (mass != 0.0f);

		btVector3 localInertia(0, 0, 0);
		if (isDynamic)
		{
			m_collider->calculateLocalInertia(mass, localInertia);
		}
		
		
		btRigidBody::btRigidBodyConstructionInfo rbInfo(mass, m_MotionState.get(), m_collider.get(), localInertia);
		body = std::make_shared<btRigidBody>(btRigidBody(rbInfo));
		getCore()->getPhysics()->getPhysics()->addRigidBody(body.get());
	}
}