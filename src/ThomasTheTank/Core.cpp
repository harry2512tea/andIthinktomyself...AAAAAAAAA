#include "Core.h"
#include "Entity.h"
#include "Components/Transform.h"
#include <string>
#include <iostream>

namespace ThomasTheTank
{
	Shared<Core> Core::Initialise()
	{
		Shared<Core> rtn = std::make_shared<Core>();
		rtn->m_self = rtn;
		return rtn;
	}

	void Core::start()
	{
		m_running = true;

		for (auto it = m_entities.begin(); it != m_entities.end(); it++)
		{
			std::cout << (*it)->name << std::endl;
		}

		while (m_running)
		{
			
			for (auto it = m_entities.begin(); it != m_entities.end(); it++)
			{
				(*it)->tick();
			}

			for (auto it = m_entities.begin(); it != m_entities.end(); it++)
			{
				(*it)->display();
			}
			
			for (auto it = m_entities.begin(); it != m_entities.end(); it++)
			{
				if (!(*it)->alive())
				{
					m_entities.erase(it);
					--it;
				}
			}
		}
	}

	void Core::stop()
	{
		m_running = false;
	}

	Shared<Entity> Core::addEntity()
	{
		Shared<Entity> rtn = std::make_shared<Entity>();

		rtn->m_core = m_self;
		rtn->m_self = rtn;

		rtn->Transform = rtn->addComponent<Transform>();
		rtn->name = std::string("Entity ") + std::to_string(m_entities.size() + 1);
		

		m_entities.push_back(rtn);
		return rtn;
	}
}
