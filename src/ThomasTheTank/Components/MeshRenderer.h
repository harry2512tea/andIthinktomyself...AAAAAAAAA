#ifndef THOMASTHETANK_MESHRENDERER_H
#define THOMASTHETANK_MESHRENDERER_H

#include "../Component.h"
#include <rend/rend.h>
#include <memory>
#include <string>

#define Shared std::shared_ptr
#define Weak std::weak_ptr

namespace ThomasTheTank
{
	struct MeshRenderer : Component
	{
		MeshRenderer();
		void SetTexture(std::string _path);
		void SetModel(std::string _path);
	private:
		void onInitialize();
		void onDisplay();

		rend::Model m_Model;
		rend::ModelRenderer m_Renderer;
		rend::Shader m_Shader;
		rend::Texture m_Texture;
	};
}

#endif