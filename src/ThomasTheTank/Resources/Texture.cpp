#include "Texture.h"
#include <exception>
#include <rend/sys/Exception.h>
#include "../Exceptions.h"
namespace ThomasTheTank
{
	void Texture::LoadTexture(const std::string _path)
	{
		try 
		{
			m_texture = std::make_shared<rend::Texture>(_path.c_str());
		}
		catch (sys::Exception& e)
		{
			throw Exception("Texture failed to load");
		}
	}
	void Texture::OnLoad()
	{
		LoadTexture(GetPath());
	}
}