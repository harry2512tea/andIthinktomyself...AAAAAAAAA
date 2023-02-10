#include "Component.h"
#include "Entity.h"

namespace ThomasTheTank
{
	void Component::kill()
	{
		if (!m_alive) return;

		m_alive = false;
	}

	void Component::onTick()
	{
	}

	void Component::onLateTick()
	{
	}

	void Component::onDisplay()
	{
	}

	void Component::onInitialize()
	{
	}
	
	void Component::onDestroy()
	{
	}

	void Component::onCollisionEnter(Shared<PhysB::CollisionRet> collision)
	{
	}

	void Component::onCollisionExit(Shared<PhysB::CollisionRet> collision)
	{
	}

	void Component::onCollisionStay(Shared<PhysB::CollisionRet> collision)
	{
	}

	void Component::onTriggerEnter(Shared<PhysB::CollisionRet> collision){}

	void Component::onTriggerExit(Shared<PhysB::CollisionRet> collision){}

	void Component::onTriggerStay(Shared<PhysB::CollisionRet> collision){}

	void Component::tick()
	{
		onTick();
	}

	void Component::lateTick()
	{
		onLateTick();
	}

	void Component::display()
	{
		onDisplay();
	}

	void Component::initialize()
	{
		onInitialize();
	}
	
	void Component::destroy()
	{
		onDestroy();
	}

	void Component::collisionEnter(Shared<PhysB::CollisionRet> collision)
	{
		onCollisionEnter(collision);
	}

	void Component::collisionExit(Shared<PhysB::CollisionRet> collision)
	{
		onCollisionExit(collision);
	}

	void Component::collisionStay(Shared<PhysB::CollisionRet> collision)
	{
		onCollisionStay(collision);
	}

	void Component::triggerEnter(Shared<PhysB::CollisionRet> collision)
	{
		onTriggerEnter(collision);
	}

	void Component::triggerExit(Shared<PhysB::CollisionRet> collision)
	{
		onTriggerExit(collision);
	}

	void Component::triggerStay(Shared<PhysB::CollisionRet> collision)
	{
		onTriggerStay(collision);
	}


	Shared<Core> Component::getCore()
	{
		return m_Entity.lock()->getCore();
	}
}