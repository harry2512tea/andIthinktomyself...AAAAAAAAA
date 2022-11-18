#include <memory>
#include <string>
#include <list>

#define Shared std::shared_ptr
#define Weak std::weak_ptr


namespace ThomasTheTank
{
	class Core;

	struct Resource;

	struct Resources
	{
		friend class Core;

		template<typename T> static Shared<T> load(std::string _path)
		{

		}

	private:
		static std::list<std::string> paths;
		static std::list<Shared<Resource>> m_Resources;
	};
}