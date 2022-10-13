#include <memory>
#include <vector>


#define Shared std::shared_ptr
#define Weak std::weak_ptr

namespace ThomasTheTank
{
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


	private:

		std::vector<Shared<Component>> m_components;

		
	};
}