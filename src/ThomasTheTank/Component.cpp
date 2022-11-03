#include "Component.h"

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

	void Component::onDisplay()
	{
	}

	void Component::onInitialize()
	{
	}
	
	void Component::onDestroy()
	{
	}

	void Component::tick()
	{
		onTick();
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
}