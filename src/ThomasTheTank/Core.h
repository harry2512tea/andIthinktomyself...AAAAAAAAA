#include <memory>
#include <list>


#define Shared std::shared_ptr
#define Weak std::weak_ptr

namespace ThomasTheTank
{
	class Entity;

	class Core
	{
	public:
		static Shared<Core> Initialise();
		void start();
		void stop();

		Shared<Entity> addEntity();


	private:
		std::list<Shared<Entity>> m_entities;
		bool m_running = false;
		Weak<Core> m_self;
	};
}