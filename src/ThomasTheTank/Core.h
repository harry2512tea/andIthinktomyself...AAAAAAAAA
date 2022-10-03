#include <memory>

#define Shared std::shared_ptr

namespace ThomasTheTank
{

	class Core
	{
	public:
		static Shared<Core> Initialise();

	private:
		int m_dumpy;
	};
}