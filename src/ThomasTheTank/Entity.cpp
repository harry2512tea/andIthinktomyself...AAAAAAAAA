#include "Entity.h"
#include "Component.h"
#include "Core.h"

namespace ThomasTheTank
{
	void Entity::kill()
	{
		if (!m_alive) return;

		m_alive = false;

		for (std::list<Shared<Component>>::iterator it = m_components.begin(); it != m_components.end(); it++)
		{
			(*it)->kill();
		}
	}

	void Entity::getWindowSize(int* w, int* h)
	{
		m_core.lock()->getWindowSize(w, h);
	}

	void Entity::tick()
	{
		for (std::list<Shared<Component>>::iterator it = m_components.begin(); it != m_components.end(); it++)
		{
			(*it)->tick();
		}
	}

	void Entity::display()
	{
		for (std::list<Shared<Component>>::iterator it = m_components.begin(); it != m_components.end(); it++)
		{
			(*it)->display();
		}
	}

	void Entity::initialize()
	{
		for (std::list<Shared<Component>>::iterator it = m_components.begin(); it != m_components.end(); it++)
		{
			(*it)->initialize();
		}
	}

	/*Weak<Camera> Entity::getMainCam()
	{
		return m_core.lock()->getMainCam();
	}*/
}