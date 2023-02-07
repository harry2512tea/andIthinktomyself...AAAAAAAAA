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
		/**
		* Function to load a texture from a specified file
		*
		* \param _path STRING path to model file
		*/
		void LoadTexture(const std::string _path);

		void OnLoad();

	private:
		friend struct MeshRenderer;
		Shared<rend::Texture> m_texture; ///< link to the loaded texture.
	};
}
#endif 