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
		Shared<Entity> getEntity() { return m_Entity.lock(); };

	protected:
		friend class Entity;

		virtual void onTick();
		virtual void onDisplay();
		virtual void onInitialize();
		virtual void onDestroy();

		void initialize();
		void tick();
		void display();
		void destroy();

		Weak<Entity> m_Entity;
		Weak<Component> m_self;
	};
}

#endif