#include "MeshRenderer.h"
#include "ThomasTheTank/Wrapping/ThomasMath.h"
#include "../Entity.h"
#include "Transform.h"
#include "Camera.h"
#include "ThomasTheTank/Resources/Model.h"
#include "ThomasTheTank/Resources/Texture.h"


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
		m_Renderer.shader(&m_Shader);
		m_Renderer.modelMat(model);
		m_Renderer.model(m_Model->m_model.get());
		m_Renderer.texture(m_Texture->m_texture.get());

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