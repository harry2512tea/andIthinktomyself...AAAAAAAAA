#include "Model.h"

namespace ThomasTheTank
{
	void Model::LoadModel(const std::string _path)
	{
		m_model = std::make_shared<rend::Model>(_path.c_str());
	}
	void Model::OnLoad()
	{
		LoadModel(GetPath());
	}
}