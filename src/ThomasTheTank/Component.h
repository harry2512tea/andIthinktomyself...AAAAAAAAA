#ifndef THOMASTHETANK_COMPONENT_H
#define THOMASTHETANK_COMPONENT_H

#include <memory>

#define Shared std::shared_ptr
#define Weak std::weak_ptr

namespace ThomasTheTank
{
	class Entity;

	struct Component
	{
		void kill();
		Weak<Entity> getEntity() { return m_Entity; };

	protected:
		friend class Entity;

		virtual void onTick();
		virtual void onDisplay();
		virtual void onInitialize();

		void initialize();
		void tick();
		void display();

		Weak<Entity> m_Entity;
		Weak<Component> m_self;
	};
}

#endif