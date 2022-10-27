#include "Component.h"

#include <rend/rend.h>

namespace ThomasTheTank
{
	struct TriangleRenderer : Component
	{
		TriangleRenderer();

	private:
		rend::ModelRenderer m_Renderer;
		rend::Model m_Mesh;
		rend::Shader m_Shader;
		void onInitialize();
		void onDisplay();
	};
}