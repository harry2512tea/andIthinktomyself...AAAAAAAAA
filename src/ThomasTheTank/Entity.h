#include <memory>
#include <list>
#include <stdexcept>
#include <string>
#include <PhysB/PhysB.h>
#include "Exceptions.h"
#include <type_traits>

#define Shared std::shared_ptr
#define Weak std::weak_ptr

namespace ThomasTheTank
{
	
	struct Core;

	struct Component;

	struct Transform;

	struct Camera;

	struct CollisionRet;

	struct Collider;

	/**
	* Main entity struct.
	*/
	struct Entity
	{
	public:
		/**
		* Add a component to the entity.
		* 
		* \param T Component struct type.
		* 
		* \return Pointer to the new component.
		*/
		template<typename T>
		Shared<T> addComponent()
		{
			//Shared<T> rtn;
			/*if (std::is_same<T, RigidBody>::value && hasRigidBody)
			{
				throw Exception("Entity already has a rigidbody");
				return nullptr;
			}*/
			//else
			//{
				//rtn = std::make_shared<T>();
				Shared<T> rtn = std::make_shared<T>();
				rtn->m_self = rtn;
				rtn->m_Entity = m_self;
				try
				{
					rtn->initialize();
				}
				catch (Exception& e)
				{
					rtn->enabled = false;
					std::cout << "Exception: " << e.what() << std::endl;
				}
				catch (...)
				{
					std::cout << "Unknown error occurred" << std::endl;
					rtn->enabled = false;
				}
				m_components.push_back(rtn);
			//}
			
			return rtn;
		}

		/**
		* Get a component attached to the entity.
		* 
		* \param T Component struct type.
		* 
		* \return Pointer to the attached Component.
		*/
		template<typename T>
		Shared<T> getComponent()
		{
			for (std::list<Shared<Component>>::iterator it = m_components.begin(); it != m_components.end(); it++)
			{
				Shared<T> rtn = std::dynamic_pointer_cast<T>(*it);
				if (rtn)
				{
					return rtn;
				}
			}
			
			std::cout << "component doesn't exist" << std::endl;
			throw Exception("Component doesn't exist");
		}

		/**
		* Get all components attached to the entity.
		*
		* \param T Component struct type.
		*
		* \return List of pointers to the attached components.
		*/
		template<typename T>
		std::list<Shared<T>> getComponents()
		{
			std::list<Shared<T>> rtn;

			int i = 0;
			for (std::list<Shared<Component>>::iterator it = m_components.begin(); it != m_components.end(); it++)
			{
				i++;
				Shared<T> test = std::dynamic_pointer_cast<T>(*it);
				if (test)
				{
					std::cout << typeid(*test).name() << std::endl;
					rtn.push_back(test);
				}
			}
			if (rtn < 1)
			{
				std::cout << "component doesn't exist" << std::endl;
				throw std::runtime_error("Component doesn't exist");
			}
			return rtn;
		}


		void kill(); ///< Function to destroy the entity.

		/**
		* Get the current state of the entity.
		* 
		* \return BOOL Current state of the entity.
		*/
		bool alive() { return m_alive; };

		/**
		* Get size of the window.
		*
		* \param INT w Pointer to output variable for width.
		* \param INT h Pointer to output variable for height.
		*/
		void getWindowSize(int *w, int*h);

		/**
		* Get the transform of the entity.
		*
		* \return Pointer to the entity's transform component.
		*/
		Shared<Transform> getTransform() { return Transform; };

		/**
		* Get a reference to the core structure
		* 
		* \return Pointer to the core structure
		*/
		Shared<Core> getCore() { return m_core.lock(); };
		std::string name; ///< Name of the entity.
	private:
		friend struct Core;
		friend struct BoxCollider;
		friend struct RigidBody;
		friend struct Collider;
		bool enabled = true; ///< Whether or not the entity is enabled.
		void addRigidBody(Shared<PhysB::PhysRigidBody> body); ///< Function called to add rigidbody references to colliders
		void removeRigidBody(); ///< Function called to remove rigidbody references from colliders
		bool hasRigidBody = false; ///< Whether the entity has a rigidbody attached
		Weak<RigidBody> m_body; ///< Link to the entity's rigidbody
		Shared<Transform> Transform; ///< Pointer to transform component.
		void initialize(); ///< Function called to trigger onInitialize.
		void tick(); ///< Function called to trigger onTick.
		void lateTick(); ///< Function called after tick and display functions.
		void display(); ///< Function called to trigger onDisplay. 
		void destroy(); ///< Function called to trigger onDestroy.
		void collisionEnter(Shared<PhysB::CollisionRet> collision); ///< Function called when entering colliders.
		void collisionExit(Shared<PhysB::CollisionRet> collision); ///< Function called when exiting colliders.
		void collisionStay(Shared<PhysB::CollisionRet> collision); ///< Function called while inside colliders.
		void triggerEnter(Shared<PhysB::CollisionRet> collision); ///< Function called when entering triggers.
		void triggerExit(Shared<PhysB::CollisionRet> collision); ///< Function called when exiting triggers.
		void triggerStay(Shared<PhysB::CollisionRet> collision); ///< Function called while inside triggers.
		std::vector<Weak<Collider>>m_colliders; ///< List of all colliders attached to the entity.
		std::list<Shared<Component>> m_components; ///< List of all components attached to the entity.
		bool m_alive = true; ///< Current state of the entity.
		Weak<Core> m_core; ///< Pointer to the core struct.
		Weak<Entity> m_self; ///< Pointer to self.
	};
}