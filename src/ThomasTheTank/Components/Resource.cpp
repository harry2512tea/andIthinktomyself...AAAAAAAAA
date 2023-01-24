#include "Resource.h"

namespace ThomasTheTank
{
	std::string Resource::GetPath() const
	{
		return m_path;
	}

	void Resource::Load()
	{
		OnLoad();
	}
}