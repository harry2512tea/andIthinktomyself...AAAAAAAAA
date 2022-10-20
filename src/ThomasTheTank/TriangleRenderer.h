#include "Component.h"
#include <rend/rend.h>

namespace ThomasTheTank
{
	struct TriangleRenderer : Component
	{
		TriangleRenderer();

	private:
		rend::Renderer m_Renderer;
		rend::Mesh m_Mesh;
		rend::Shader m_Shader;
		void onInitialize();
		void onDisplay();
	};
}