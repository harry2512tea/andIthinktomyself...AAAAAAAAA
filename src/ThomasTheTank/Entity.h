#include <memory>
#include <list>


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

		void kill();
		bool alive() {return m_alive};

	private:
		friend class Core;
		void tick();
		void display();
		std::list<Shared<Component>> m_components;
		bool m_alive;
		
	};
}