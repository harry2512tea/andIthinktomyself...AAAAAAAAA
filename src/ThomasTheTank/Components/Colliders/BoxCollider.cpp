#include "BoxCollider.h"
#include "ThomasTheTank/Core.h"
#include "ThomasTheTank/Entity.h"
#include "ThomasTheTank/Components/Transform.h"
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
		m_collider = getCore()->getPhysics()->AddCollider<PhysB::PhysAABB>(m_Entity.lock()->getTransform()->getPhysicsTransform());
		m_collider.lock()->setEventHandler(std::dynamic_pointer_cast<PhysB::CollisionEvent>(m_self.lock()));
	}
	void BoxCollider::onTick()
	{
	}
}