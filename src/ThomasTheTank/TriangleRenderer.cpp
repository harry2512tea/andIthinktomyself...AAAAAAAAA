#include "TriangleRenderer.h"
#include "ThomasTheTank/Wrapping/ThomasMath.h"
#include "Entity.h"
#include "Components/Transform.h"
#include "Components/Camera.h"

namespace ThomasTheTank
{
	TriangleRenderer::TriangleRenderer():
		m_Renderer(1280, 720),
		m_Shader("../data/shaders/basic.vert", "../data/shaders/basic.frag")
	{}

	void TriangleRenderer::onInitialize()
	{
		m_Mesh.loadTriangle();
	}

	void TriangleRenderer::onDisplay()
	{
		//mat4 model = m_Entity.lock()->getTransform()->getModel();
		//m_Renderer.depthTest(true);
		m_Renderer.shader(&m_Shader);
		m_Renderer.mesh(&m_Mesh);
		//m_Renderer.modelMat(model);
		//m_Renderer.modelMat(mat4(1.0f));
		//m_Renderer.view(mat4(1.0f));
		//m_Renderer.projection(mat4(1.0f));

		//Shared<Camera> cam = Camera::main();
		//if (cam)
		{
			//m_Renderer.projection(cam->getProjection());
			//m_Renderer.view(cam->getView());
		}
		m_Renderer.render();
	}
}