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

	void Component::onCollisionEnter(Shared<CollisionRet> collision)
	{
	}

	void Component::onCollisionExit(Shared<CollisionRet> collision)
	{
	}

	void Component::onCollisionStay(Shared<CollisionRet> collision)
	{
	}

	void Component::onTriggerEnter(Shared<CollisionRet> collision){}

	void Component::onTriggerExit(Shared<CollisionRet> collision){}

	void Component::onTriggerStay(Shared<CollisionRet> collision){}

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

	void Component::collisionEnter(Shared<CollisionRet> collision)
	{
		onCollisionEnter(collision);
	}

	void Component::collisionExit(Shared<CollisionRet> collision)
	{
		onCollisionExit(collision);
	}

	void Component::collisionStay(Shared<CollisionRet> collision)
	{
		onCollisionStay(collision);
	}

	void Component::triggerEnter(Shared<CollisionRet> collision)
	{
		onTriggerEnter(collision);
	}

	void Component::triggerExit(Shared<CollisionRet> collision)
	{
		onTriggerExit(collision);
	}

	void Component::triggerStay(Shared<CollisionRet> collision)
	{
		onTriggerStay(collision);
	}


	Shared<Core> Component::getCore()
	{
		return m_Entity.lock()->getCore();
	}
}