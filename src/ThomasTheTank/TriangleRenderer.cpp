#include "TriangleRenderer.h"
#include "ThomasTheTank/Wrapping/ThomasMath.h"
#include "Entity.h"
#include "Components/Transform.h"

namespace ThomasTheTank
{
	TriangleRenderer::TriangleRenderer():
		m_Renderer(1280, 720),
		m_Shader("../data/shaders/basic.vert", "../data/shaders/basic.frag"),
		m_Mesh("../data/curuthers/curuthers.obj"),
		m_Texture("../data/curuthers/Whiskers_diffuse.jpg")
	{}

	void TriangleRenderer::onInitialize()
	{
		//m_Mesh.load("../data/curuthers/curuthers.obj");
	}

	void TriangleRenderer::onDisplay()
	{
		mat4 model = m_Entity.lock()->getTransform()->getModel();
		m_Renderer.depthTest(true);
		m_Renderer.texture(&m_Texture);
		m_Renderer.shader(&m_Shader);
		m_Renderer.model(&m_Mesh);
		m_Renderer.modelMat(model);
		m_Renderer.render();
	}
}