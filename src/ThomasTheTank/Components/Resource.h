#include <memory>
#include <string>
#include <list>

#define Shared std::shared_ptr
#define Weak std::weak_ptr


namespace ThomasTheTank
{
	struct Core;

	struct Resource;

	struct Resources
	{
		friend struct Core;

		template<typename T> static Shared<T> load(std::string _path)
		{

		}

	private:
		static std::list<std::string> paths;
		static std::list<Shared<Resource>> m_Resources;
	};
}