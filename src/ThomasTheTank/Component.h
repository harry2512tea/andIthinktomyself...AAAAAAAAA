#ifndef THOMASTHETANK_COMPONENT_H
#define THOMASTHETANK_COMPONENT_H

#include <memory>
#include <vector>

#define Shared std::shared_ptr
#define Weak std::weak_ptr

namespace ThomasTheTank
{
	struct Entity;

	struct Core;

	struct CollisionInfo;
	/**
	* Base struct inherited by all components
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
		friend struct Entity;

		virtual void onTick(); ///< Overwriteable funciton called on every tick of the program
		virtual void onLateTick();
		virtual void onDisplay(); ///< Overwriteable Function called on every render tick of the program
		virtual void onInitialize(); ///< Overwriteable Function called on creation of component
		virtual void onDestroy(); ///< Overwriteable Function called on destruction of component

		/**
		* Overwritable function called when the entity enters a collision.
		* 
		* \param collision Shared<CollisionInfo> Shared pointer to the collision information struct.
		*/
		virtual void onCollisionEnter(Shared<CollisionInfo> collision); 

		/**
		* Overwritable function called when the entity exits a collision.
		*
		* \param collision Shared<CollisionInfo> Shared pointer to the collision information struct.
		*/
		virtual void onCollisionExit(Shared<CollisionInfo> collision);

		/**
		* Overwritable function called when the entity stays in a collision.
		*
		* \param collision Shared<CollisionInfo> Shared pointer to the collision information struct.
		*/
		virtual void onCollisionStay(Shared<CollisionInfo> collision);

		/**
		* Overwritable function called when the entity enters a trigger.
		*
		* \param collision Shared<CollisionInfo> Shared pointer to the collision information struct.
		*/
		virtual void onTriggerEnter(Shared<CollisionInfo> collision);

		/**
		* Overwritable function called when the entity exits a trigger.
		*
		* \param collision Shared<CollisionInfo> Shared pointer to the collision information struct.
		*/
		virtual void onTriggerExit(Shared<CollisionInfo> collision);

		/**
		* Overwritable function called when the entity stays in a trigger.
		*
		* \param collision Shared<CollisionInfo> Shared pointer to the collision information struct.
		*/
		virtual void onTriggerStay(Shared<CollisionInfo> collision);

		void initialize(); ///< Function called to trigger onInitialize 
		void tick(); ///< Function called to trigger onTick 
		void lateTick();
		void display(); ///< Function called to trigger onDisplay 
		void destroy(); ///< Function called to trigger onDestroy 

		/**
		* Function called when the entity enters a collision.
		*
		* \param collision Shared<CollisionInfo> Shared pointer to the collision information struct.
		*/
		void collisionEnter(Shared<CollisionInfo> collision);

		/**
		* Function called when the entity exits a collision.
		*
		* \param collision Shared<CollisionInfo> Shared pointer to the collision information struct.
		*/
		void collisionExit(Shared<CollisionInfo> collision);

		/**
		* Function called when the entity stays in a collision.
		*
		* \param collision Shared<CollisionInfo> Shared pointer to the collision information struct.
		*/
		void collisionStay(Shared<CollisionInfo> collision);

		/**
		* Function called when the entity enters a trigger.
		*
		* \param collision Shared<CollisionInfo> Shared pointer to the collision information struct.
		*/
		void triggerEnter(Shared<CollisionInfo> collision);

		/**
		* Function called when the entity exits a trigger.
		*
		* \param collision Shared<CollisionInfo> Shared pointer to the collision information struct.
		*/
		void triggerExit(Shared<CollisionInfo> collision);

		/**
		* Function called when the entity stays in a trigger.
		*
		* \param collision Shared<CollisionInfo> Shared pointer to the collision information struct.
		*/
		void triggerStay(Shared<CollisionInfo> collision);

		std::vector<Shared<CollisionInfo>> colInfo;


		bool m_alive = true; ///< Current state of the component

	protected:
		friend struct Entity;
		bool enabled = true; ///< whether the component is enabled
		Shared<Core> getCore(); ///< returns a link to the core struct
		Weak<Entity> m_Entity; ///< Pointer to the component's parent entity
		Weak<Component> m_self; ///< Pointer to self
	};
}

#endif