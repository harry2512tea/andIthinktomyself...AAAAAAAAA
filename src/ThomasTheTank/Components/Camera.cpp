#include "Camera.h"
#include "Transform.h"
#include "../Entity.h"

namespace ThomasTheTank
{

	mat4 Camera::getProjection()
	{
		int w = 1920, h = 1080;
		getEntity().lock()->getWindowSize(&w, &h);
		return perspective(radians(FOV), (float)w/ (float)h, nearClip, farClip);
	}

	mat4 Camera::getView()
	{
		glm::mat4 viewMat;
		Shared<Transform> trans = getEntity().lock()->getTransform();
		viewMat = mat4_cast(-trans->getRotationQuat());
		viewMat = translate(viewMat, -trans->getPosition());
		return viewMat;
	}
}