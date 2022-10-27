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

	class Entity
	{
	public:
		template<typename T>
		Shared<T> addComponent()
		{
			Shared<T> rtn = std::make_shared<T>();
			rtn->m_self = rtn;
			rtn->m_Entity = m_self;
			m_components.push_back(rtn);

			return rtn;
		}

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


		void kill();
		bool alive() { return m_alive; };

		Shared<Transform> getTransform() { return Transform; };
		std::string name;
	private:
		friend class Core;

		Shared<Transform> Transform;
		void tick();
		void display();
		void initialize();
		std::list<Shared<Component>> m_components;
		bool m_alive = true;
		Weak<Core> m_core;
		Weak<Entity> m_self;
	};
}