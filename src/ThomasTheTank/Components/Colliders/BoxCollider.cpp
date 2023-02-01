#include "BoxCollider.h"
#include "ThomasTheTank/Core.h"
#include "ThomasTheTank/Entity.h"
#include "ThomasTheTank/Components/Transform.h"
#include <iostream>

namespace ThomasTheTank
{
	void BoxCollider::onInitialize()
	{
		std::cout << "collider init" << std::endl;
		m_trans = getEntity()->getTransform();
		if (!m_trans->m_PhysTransform)
		{
			m_trans->addPhysicsTransform();
			m_trans->m_PhysTransform->initialise(glm::vec3(0.0f, 0.0f, 0.0f));
		}
		getCore()->getPhysics()->AddCollider<PhysB::PhysAABB>(m_Entity.lock()->getTransform()->getPhysicsTransform());
	}
	void BoxCollider::onTick()
	{
	}
}