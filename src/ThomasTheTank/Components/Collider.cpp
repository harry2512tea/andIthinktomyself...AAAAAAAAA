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

	void Collider::physOnCollisionEnter(Shared<CollisionInfo> collision)
	{
		m_Entity.lock()->collisionEnter(collision);
	}

	void Collider::physOnCollisionExit(Shared<CollisionInfo> collision)
	{
		m_Entity.lock()->collisionExit(collision);
	}

	void Collider::physOnCollisionStay(Shared<CollisionInfo> collision)
	{
		m_Entity.lock()->collisionStay(collision);
	}
}