#ifndef THOMASTHETANK_RESOURCE_H
#define THOMASTHETANK_RESOURCE_H

#include <memory>
#include <string>
#include <list>

#define Shared std::shared_ptr
#define Weak std::weak_ptr


namespace ThomasTheTank
{
	struct Core;

	struct Cache;

	struct Resource
	{
		virtual void OnLoad() = 0;

		std::string GetPath() const;
	private:
		friend struct Cache;
		std::string m_path;

		void Load();
	};
}
#endif