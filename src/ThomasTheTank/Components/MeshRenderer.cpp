#include "MeshRenderer.h"
#include "ThomasTheTank/Wrapping/ThomasMath.h"
#include "../Entity.h"
#include "Transform.h"
#include "Camera.h"
#include "ThomasTheTank/Resources/Model.h"
#include "ThomasTheTank/Resources/Texture.h"
#include <iostream>

namespace ThomasTheTank
{
	MeshRenderer::MeshRenderer() :
		m_Renderer(1280, 720),
		m_Shader("../data/shaders/basic.vert", "../data/shaders/basic.frag")
	{}

	void MeshRenderer::SetTexture(Shared<Texture> _Texture)
	{
		m_Texture = _Texture;
	}

	void MeshRenderer::SetModel(Shared<Model> _Model)
	{
		m_Model = _Model;
	}

	void MeshRenderer::onDisplay()
	{
		mat4 model = getEntity()->getTransform()->getModel();
		mat4 scaleMat = mat4();
		model *= glm::scale(scaleMat, scale);
		m_Renderer.shader(&m_Shader);
		m_Renderer.modelMat(model);

		if (m_Model)
		{
			m_Renderer.model(m_Model->m_model.get());
		}
		else
		{
			throw Exception("Model not found");
		}

		if (m_Texture)
		{
			m_Renderer.texture(m_Texture->m_texture.get());
		}
		else
		{
			throw Exception("Texture not found");
		}
		
		
		

		m_Renderer.depthTest(true);
		m_Renderer.backfaceCull(true);
		m_Renderer.blend(true);

		Shared<Camera> cam = Camera::main();
		if (cam)
		{
			m_Renderer.projection(cam->getProjection());
			m_Renderer.view(cam->getView());
		}

		m_Renderer.render();
	}
}