#include "Component.h"

namespace ThomasTheTank
{
	void Component::onTick()
	{
	}
	void Component::onDisplay()
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
}