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
	struct Model;
	struct Texture;

	/**
	* Component to render meshes.
	*/
	struct MeshRenderer : Component
	{
		MeshRenderer(); ///< Component constructor with default values.

		/**
		* Set the texture to use for rendering.
		* 
		* \param STRING _path Path to texture file.
		*/
		void SetTexture(Shared<Texture> _Texture);

		/**
		* Set the model to use for rendering.
		*
		* \param STRING _path Path to model file.
		*/
		void SetModel(Shared<Model> _Model);
	private:
		void onInitialize(); ///< Function called on the creation of the component.
		void onDisplay(); ///< Function called on the render tick of the program.

		Shared<Model> m_Model; ///< Model to render.
		rend::Shader m_Shader; ///< Shader to use.
		Shared<Texture> m_Texture; ///< Texture to use.
		rend::ModelRenderer m_Renderer; ///< Renderer to use.
	};
}

#endif