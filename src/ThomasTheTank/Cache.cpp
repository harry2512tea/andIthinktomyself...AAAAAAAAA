#include "Cache.h"

namespace ThomasTheTank
{
	Shared<Cache> Cache::m_self = nullptr;

	Shared<Cache> Cache::Initialise()
	{
		Shared<Cache> temp = std::make_shared<Cache>();
		Cache::m_self = temp;
		return temp;
	}

	Shared<Cache> Cache::getInstance()
	{
		return Cache::m_self;
	}
}