#include "MeshRenderer.h"
#include "ThomasTheTank/Wrapping/ThomasMath.h"
#include "../Entity.h"
#include "Transform.h"
#include "Camera.h"

namespace ThomasTheTank
{
	MeshRenderer::MeshRenderer() :
		m_Renderer(1280, 720),
		m_Model("../data/default/cube.obj"),
		m_Shader("../data/shaders/basic.vert", "../data/shaders/basic.frag")
	{}

	void MeshRenderer::SetTexture(std::string _path)
	{
		m_Texture = rend::Texture(_path.c_str());
		m_Renderer.texture(&m_Texture);
	}

	void MeshRenderer::SetModel(std::string _path)
	{
		m_Model.setModel(_path.c_str());
	}

	void MeshRenderer::onInitialize()
	{
		m_Renderer.depthTest(true);
		m_Renderer.shader(&m_Shader);
		m_Renderer.model(&m_Model);
	}

	void MeshRenderer::onDisplay()
	{
		mat4 model = getEntity().lock()->getTransform()->getModel();
		m_Renderer.modelMat(model);
		Shared<Camera> cam = Camera::main();
		if (cam)
		{
			m_Renderer.projection(cam->getProjection());
			m_Renderer.view(cam->getView());
		}


		m_Renderer.render();
	}
}