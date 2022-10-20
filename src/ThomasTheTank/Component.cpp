#include "Component.h"

namespace ThomasTheTank
{
	void Component::kill()
	{
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
}