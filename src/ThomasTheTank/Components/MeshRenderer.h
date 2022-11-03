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
	/**
	* Component to render meshes.
	*/
	struct MeshRenderer : Component
	{
		MeshRenderer(); ///< Component constructor with default values.

		/**
		* Set the texture to use for rendering.
		* 
		* \param _path Path to texture file.
		*/
		void SetTexture(std::string _path);

		/**
		* Set the model to use for rendering.
		*
		* \param _path Path to model file.
		*/
		void SetModel(std::string _path);
	private:
		void onInitialize(); ///< Function called on the creation of the component.
		void onDisplay(); ///< Function called on the render tick of the program.

		rend::Model m_Model; ///< Model to render.
		rend::ModelRenderer m_Renderer; ///< Renderer to use.
		rend::Shader m_Shader; ///< Shader to use.
		rend::Texture m_Texture; ///< Texture to use.
	};
}

#endif