#include "Texture.h"

namespace ThomasTheTank
{
	void Texture::LoadTexture(const std::string _path)
	{
		m_texture = std::make_shared<rend::Texture>(_path.c_str());
	}
	void Texture::OnLoad()
	{
		LoadTexture(GetPath());
	}
}