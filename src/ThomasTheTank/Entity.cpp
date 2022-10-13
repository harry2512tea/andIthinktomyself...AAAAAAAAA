#include "Entity.h"
#include "Component.h"

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
}