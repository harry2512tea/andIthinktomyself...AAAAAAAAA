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

	void Component::onCollisionEnter(Shared<CollisionInfo> collision)
	{
	}

	void Component::onCollisionExit(Shared<CollisionInfo> collision)
	{
	}

	void Component::onCollisionStay(Shared<CollisionInfo> collision)
	{
	}

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

	void Component::collisionEnter(Shared<CollisionInfo> collision)
	{
		onCollisionEnter(collision);
	}

	void Component::collisionExit(Shared<CollisionInfo> collision)
	{
		onCollisionExit(collision);
	}

	void Component::collisionStay(Shared<CollisionInfo> collision)
	{
		onCollisionStay(collision);
	}


	Shared<Core> Component::getCore()
	{
		return m_Entity.lock()->getCore();
	}
}