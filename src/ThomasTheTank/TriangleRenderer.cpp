#include "TriangleRenderer.h"

namespace ThomasTheTank
{
	TriangleRenderer::TriangleRenderer():
		m_Renderer(1920, 1080),
		m_Shader("data/shaders/basic.vert", "data/shaders/basic.frag")
	{}

	void TriangleRenderer::onInitialize()
	{
		m_Mesh.loadTriangle();
	}

	void TriangleRenderer::onDisplay()
	{
		m_Renderer.shader(&m_Shader);
		m_Renderer.mesh(&m_Mesh);

		m_Renderer.render();
	}
}