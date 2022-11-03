#ifndef THOMASTHETANK_COMPONENT_H
#define THOMASTHETANK_COMPONENT_H

#include <memory>

#define Shared std::shared_ptr
#define Weak std::weak_ptr

namespace ThomasTheTank
{
	class Entity;

	/**
	* Base class inherited by all components
	*/
	struct Component
	{
		void kill(); ///< Function to destroy the component

		/**
		* Get pointer to the entity the component is attached to
		* 
		* \return Pointer to parent entity
		*/
		Shared<Entity> getEntity() { return m_Entity.lock(); };

	private:
		friend class Entity;

		virtual void onTick(); ///< Overwriteable funciton called on every tick of the program
		virtual void onDisplay(); ///< Overwriteable Function called on every render tick of the program
		virtual void onInitialize(); ///< Overwriteable Function called on creation of component
		virtual void onDestroy(); ///< Overwriteable Function called on destruction of component

		void initialize(); ///< Function called to trigger onInitialize 
		void tick(); ///< Function called to trigger onTick 
		void display(); ///< Function called to trigger onDisplay 
		void destroy(); ///< Function called to trigger onDestroy 

		bool m_alive = true; ///< Current state of the component

	protected:
		Weak<Entity> m_Entity; ///< Pointer to the component's parent entity
		Weak<Component> m_self; ///< Pointer to self
	};
}

#endif