#include "Core.h"

namespace ThomasTheTank
{
	Shared<Core> Core::Initialise()
	{
		Shared<Core> rtn = std::make_shared<Core>();
		return rtn;
	}
}
