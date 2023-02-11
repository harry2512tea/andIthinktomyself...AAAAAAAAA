#ifndef THOMASTHETANK_CACHE_H
#define THOMASTHETANK_CACHE_H

#include <memory>
#include <string>
#include <list>
#include <vector>
#include "Exceptions.h"

#define Shared std::shared_ptr
#define Weak std::weak_ptr

namespace ThomasTheTank
{
	struct Resource;

	struct Core;

	struct Cache
	{
		/*
		* Open a resource file and load it. resources include textures, models, audio clips etc.
		* 
		* 
		* \param STRING _path file path to the resource to open.
		* \return pointer to the loaded resource.
		*/
		template <typename T>
		Shared<T> load(const std::string& _path)
		{
			
			for (size_t i = 0; i < m_resources.size(); i++)
			{
				if (m_resources.at(i)->GetPath() == _path)
				{
					Shared<T> rtn = std::dynamic_pointer_cast<T>(m_resources.at(i));
					return rtn;
				}
			}
			Shared<T> rtn = std::make_shared<T>();
			//try
		//	{
				rtn->m_path = _path;
				rtn->Load();
				m_resources.push_back(rtn);
				return rtn;
			//}
			/*catch (Exception& e)
			{
				std::cout << "Exception: " << e.what() << std::endl;
			}
			catch (std::exception)
			{
				std::cout << "An unknown exception was thrown" << std::endl;
			}*/
		}

	private:
		friend struct Core;
		std::vector<Shared<Resource>> m_resources = {}; ///< list of every loaded resource

		//static Shared<Cache> m_self;

		/*
		* Create an instance of the Cache struct
		*
		*
		*
		* \return Pointer to cache struct
		*/
		static Shared<Cache> Initialise();
	};
}

#endif 