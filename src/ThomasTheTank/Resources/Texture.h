#ifndef THOMASTHETANK_TEXTURE_H
#define THOMASTHETANK_TEXTURE_H

#include "ThomasTheTank/Components/Resource.h"
#include <rend/rend.h>
#include <list>

namespace ThomasTheTank
{
	struct MeshRenderer;

	struct Texture : Resource
	{
		void LoadTexture(const std::string _path);

		void OnLoad();

	private:
		friend struct MeshRenderer;
		Shared<rend::Texture> m_texture;
	};
}
#endif 