#ifndef THOMASTHETANK_COMPONENT_H
#define THOMASTHETANK_COMPONENT_H

#define Shared std::shared_ptr
#define Weak std::weak_ptr

namespace ThomasTheTank
{

	class Component
	{
	private:
		virtual void onTick();
		virtual void onDisplay();

		void tick();
		void display();
	};
}

#endif