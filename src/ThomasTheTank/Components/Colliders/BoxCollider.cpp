#include "BoxCollider.h"
#include "ThomasTheTank/Core.h"
#include "ThomasTheTank/Entity.h"
#include "ThomasTheTank/Components/Transform.h"
#include "ThomasTheTank/Components/RigidBody.h"
#include <iostream>

namespace ThomasTheTank
{
	void BoxCollider::onInitialize()
	{
		std::cout << "box collider init" << std::endl;
		m_trans = getEntity()->getTransform();
		if (!m_trans->m_PhysTransform)
		{
			m_trans->addPhysicsTransform();
			m_trans->m_PhysTransform->initialise(m_trans->getPosition());
		}
		
		m_Entity.lock()->m_colliders.push_back(std::dynamic_pointer_cast<Collider>(m_self.lock()));
		m_collider = getCore()->getPhysics()->AddCollider<PhysB::PhysAABB>(m_Entity.lock()->getTransform()->getPhysicsTransform());
		m_collider.lock()->setEventHandler(std::dynamic_pointer_cast<PhysB::CollisionEvent>(m_self.lock()));

		if (m_Entity.lock()->hasRigidBody)
		{
			m_body = m_Entity.lock()->m_body.lock()->m_body;
			m_collider.lock()->addRigidBody(m_body.lock());
		}
	}

	void BoxCollider::onTick()
	{
	}

	void BoxCollider::onAddRigidBody(Shared<PhysB::PhysRigidBody> _body)
	{
		m_collider.lock()->addRigidBody(_body);
	}

	void BoxCollider::onRemoveRigidBody()
	{
		m_collider.lock()->removeRigidBody();
	}

	void BoxCollider::setSize(vec3 _size)
	{
		size = _size;
		m_collider.lock()->setSize(_size);
	}
}