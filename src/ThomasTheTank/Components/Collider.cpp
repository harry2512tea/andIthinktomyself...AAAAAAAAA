#include "Collider.h"
#include "../Entity.h"
#include "Transform.h"
#include "../Core.h"
#include <PhysB/PhysB.h>
#include <iostream>

namespace ThomasTheTank
{
	void Collider::onAddRigidBody(Shared<PhysB::PhysRigidBody> _body)
	{
	}
	void Collider::onRemoveRigidBody()
	{
	}
	void Collider::AddRigidBody(Shared<PhysB::PhysRigidBody> _body)
	{
		onAddRigidBody(_body);
	}
	void Collider::RemoveRigidBody()
	{
		onRemoveRigidBody();
	}
	void Collider::onInitialize()
	{
	}

	void Collider::onTick()
	{
	}

	void Collider::onDestroy()
	{
	}

	void Collider::physOnCollisionEnter(Shared<PhysB::CollisionRet> collision)
	{
		m_Entity.lock()->collisionEnter(collision);
	}

	void Collider::physOnCollisionExit(Shared<PhysB::CollisionRet> collision)
	{
		m_Entity.lock()->collisionExit(collision);
	}

	void Collider::physOnCollisionStay(Shared<PhysB::CollisionRet> collision)
	{
		m_Entity.lock()->collisionStay(collision);
	}
	void Collider::physOnTriggerEnter(Shared<PhysB::CollisionRet> collision)
	{
		m_Entity.lock()->triggerEnter(collision);
	}
	void Collider::physOnTriggerExit(Shared<PhysB::CollisionRet> collision)
	{
		m_Entity.lock()->triggerExit(collision);
	}
	void Collider::physOnTriggerStay(Shared<PhysB::CollisionRet> collision)
	{
		m_Entity.lock()->triggerStay(collision);
	}
}