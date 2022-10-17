#include <memory>
#include <list>
#include <stdexcept>


#define Shared std::shared_ptr
#define Weak std::weak_ptr

namespace ThomasTheTank
{
	
	class Core;

	class Component;

	class Entity
	{
	public:
		template<typename T>
		Shared<T> addComponent()
		{
			Shared<T> rtn = std::make_shared<T>();

			m_components.push_back(rtn);

			return rtn;
		}

		template<typename T>
		Shared<T> getComponent()
		{
			Shared<T> rtn = NULL;

			int i = 0;
			for (std::list<Shared<Component>>::iterator it = m_components.begin(); it != m_components.end(); it++)
			{
				i++;
				Shared<T> test = std::dynamic_pointer_cast<T>(*it);
				if (test)
				{
					std::cout << typeid(*test).name() << std::endl;
					rtn = test;
					break;
				}
			}
			if (!rtn)
			{
				std::cout << "component doesn't exist" << std::endl;
				throw std::runtime_error("Component doesn't exist");
			}
			return rtn;
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

	private:
		friend class Core;
		void tick();
		void display();
		std::list<Shared<Component>> m_components;
		bool m_alive;
		
	};
}