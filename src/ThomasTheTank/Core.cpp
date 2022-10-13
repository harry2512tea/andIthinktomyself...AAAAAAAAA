#include "Core.h"
#include "Entity.h"

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

		while (m_running)
		{

		}
	}

	void Core::stop()
	{
		m_running = false;
	}

	Shared<Entity> Core::addEntity()
	{
		Shared<Entity> rtn = std::make_shared<Entity>();
		m_entities.push_back(rtn);
		return rtn;
	}
}