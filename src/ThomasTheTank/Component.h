#ifndef THOMASTHETANK_COMPONENT_H
#define THOMASTHETANK_COMPONENT_H

#define Shared std::shared_ptr
#define Weak std::weak_ptr

namespace ThomasTheTank
{
	class Entity;

	class Component
	{
	public:
		void kill();

	private:
		friend class Entity;

		virtual void onTick();
		virtual void onDisplay();

		void tick();
		void display();
	};
}

#endif