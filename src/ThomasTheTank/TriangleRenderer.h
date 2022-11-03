#include "Component.h"

#include <rend/rend.h>

namespace ThomasTheTank
{
	struct TriangleRenderer : Component
	{
		TriangleRenderer();
		
	private:

		rend::Mesh m_Mesh;
		rend::Shader m_Shader;
		rend::Renderer m_Renderer;
		void onInitialize();
		void onDisplay();
	};
}