#include "RigidBody.h"
#include "ThomasTheTank/Entity.h"
#include "ThomasTheTank/Core.h"
#include "ThomasTheTank/Components/Collider.h"
#include "Transform.h"
#include <iostream>

namespace ThomasTheTank
{
	void RigidBody::AddForce(glm::vec3 force, PhysB::ForceMode _mode)
	{
		m_body->AddForce(force, _mode);
	}

	float RigidBody::getMass()
	{
		return m_body->getMass();
	}

	void RigidBody::setMass(float _mass)
	{
		m_body->setMass(_mass);
	}

	bool RigidBody::getUseGravity()
	{
		return m_body->getUseGravity();
	}

	void RigidBody::setUseGravity(bool _gravity)
	{
		m_body->setUseGravity(_gravity);
	}

	vec3 RigidBody::getVelocity()
	{
		return m_body->getVelocity();
	}

	void RigidBody::setVelocity(vec3 _vel)
	{
		m_body->setVelocity(_vel);
	}

	vec3 RigidBody::getAngularVelocity()
	{
		return m_body->getAngularVelocity();
	}

	void RigidBody::setAngularVelocity(vec3 _vel)
	{
		m_body->setAngularVelocity(_vel);
	}

	float RigidBody::getElasticity()
	{
		return m_body->getElasticity();
	}

	void RigidBody::setElasticity(float _elasticity)
	{
		m_body->setElasticity(_elasticity);
	}

	float RigidBody::getFriction()
	{
		return m_body->getFriction();
	}

	void RigidBody::setFriction(float _friction)
	{
		m_body->setFriction(_friction);
	}

	void RigidBody::onInitialize()
	{
		Shared<Transform> m_trans = getEntity()->getTransform();
		if (!m_trans->m_PhysTransform)
		{
			m_trans->addPhysicsTransform();
			m_trans->m_PhysTransform->initialise(m_trans->getPosition());
		}

		m_body = m_Entity.lock()->getCore()->getPhysics()->AddRigidBody(m_trans->m_PhysTransform);

		m_Entity.lock()->hasRigidBody = true;
		m_Entity.lock()->m_body = std::dynamic_pointer_cast<RigidBody>(m_self.lock());

		for (size_t I = 0; I < m_Entity.lock()->m_colliders.size(); I++)
		{
			m_Entity.lock()->m_colliders.at(I).lock()->AddRigidBody(m_body);
		}
	}
	void RigidBody::onDestroy()
	{
		m_Entity.lock()->hasRigidBody = false;
		for (size_t I = 0; I < m_Entity.lock()->m_colliders.size(); I++)
		{
			m_Entity.lock()->m_colliders.at(I).lock()->RemoveRigidBody();
		}
	}
}
