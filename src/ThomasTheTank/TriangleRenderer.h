#include "Component.h"

#include <rend/rend.h>

namespace ThomasTheTank
{
	/**
	* Render black 2D triangle.
	*/
	struct TriangleRenderer : Component
	{
		TriangleRenderer(); ///< Constructor for the component.
		
	private:

		rend::Mesh m_Mesh; ///< Mesh to render.
		rend::Shader m_Shader; ///< Shader to use.
		rend::Renderer m_Renderer; ///< Renderer to use.
		void onInitialize(); ///< Function called on creation of the component.
		void onDisplay(); ///< Function called on every display tick of the program.
	};
}