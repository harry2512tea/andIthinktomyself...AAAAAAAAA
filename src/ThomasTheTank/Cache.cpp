#include "Cache.h"

namespace ThomasTheTank
{

	Shared<Cache> Cache::Initialise()
	{
		Shared<Cache> temp = std::make_shared<Cache>();
		return temp;
	}
}