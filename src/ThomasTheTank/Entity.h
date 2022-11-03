#include <memory>
#include <list>
#include <stdexcept>
#include <string>

#define Shared std::shared_ptr
#define Weak std::weak_ptr

namespace ThomasTheTank
{
	
	class Core;

	struct Component;

	struct Transform;

	struct Camera;
	/**
	* Main entity class.
	*/
	class Entity
	{
	public:
		/**
		* Add a component to the entity.
		* 
		* \param T Component class type.
		* 
		* \return Pointer to the new component.
		*/
		template<typename T>
		Shared<T> addComponent()
		{
			Shared<T> rtn = std::make_shared<T>();
			rtn->m_self = rtn;
			rtn->m_Entity = m_self;
			rtn->initialize();
			m_components.push_back(rtn);
			return rtn;
		}

		/**
		* Get a component attached to the entity.
		* 
		* \param T Component class type.
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
			throw std::runtime_error("Component doesn't exist");
		}

		/**
		* Get all components attached to the entity.
		*
		* \param T Component class type.
		*
		* \return list of pointers to the attached components.
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
		* \return bool of the current state of the entity.
		*/
		bool alive() { return m_alive; };

		/**
		* Get size of the window.
		*
		* \param w pointer to output variable for width.
		* \param h pointer to output variable for height.
		*/
		void getWindowSize(int *w, int*h);

		/**
		* Get the transform of the entity.
		*
		* \return Pointer to the entity's transform component.
		*/
		Shared<Transform> getTransform() { return Transform; };
		std::string name; ///< Name of the entity.
	private:
		friend class Core;

		Shared<Transform> Transform; ///< Pointer to transform component.
		void initialize(); ///< Function called to trigger onInitialize.
		void tick(); ///< Function called to trigger onTick.
		void display(); ///< Function called to trigger onDisplay. 
		void destroy(); ///< Function called to trigger onDestroy.
		std::list<Shared<Component>> m_components; ///< List of all components attached to the entity.
		bool m_alive = true; ///< Current state of the entity.
		Weak<Core> m_core; ///< Pointer to the core class.
		Weak<Entity> m_self; ///< Pointer to self.
	};
}