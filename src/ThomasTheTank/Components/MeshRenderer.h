#ifndef THOMASTHETANK_MESHRENDERER_H
#define THOMASTHETANK_MESHRENDERER_H

#include "../Component.h"
#include "../Wrapping/ThomasMath.h"
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

		void setScale(vec3 _scale) { scale = _scale; };
		vec3 getScale() { return scale; };
	private:
		void onInitialize(){}; ///< Function called on the creation of the component.
		void onDisplay(); ///< Function called on the render tick of the program.

		vec3 scale = vec3(1.0f);
		Shared<Model> m_Model; ///< Model to render.
		rend::Shader m_Shader; ///< Shader to use.
		Shared<Texture> m_Texture; ///< Texture to use.
		rend::ModelRenderer m_Renderer; ///< Renderer to use.
	};
}

#endif