#include "Model.h"
#include <rend/rend.h>
#include <rend/sys/Exception.h>
#include "../Exceptions.h"
#include <string>

namespace ThomasTheTank
{
	void Model::LoadModel(const std::string _path)
	{
		try {
			m_model = std::make_shared<rend::Model>(_path.c_str());
		}
		catch (sys::Exception& e)
		{
			throw Exception("Model failed to load");
		}
	}
	void Model::OnLoad()
	{
		LoadModel(GetPath());
	}
}