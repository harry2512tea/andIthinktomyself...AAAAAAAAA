#include "Camera.h"
#include "Transform.h"
#include "../Entity.h"

namespace ThomasTheTank
{
	Shared<Camera> Camera::mainCam = nullptr;
	std::list<Weak<Camera>> Camera::cameras = {};

	Shared<Camera> Camera::main()
	{
		return mainCam;
	}

	/*Camera::~Camera()
	{
		Weak<Camera> cam = shared_from_this();
		Camera::cameras.remove(cam);
	}*/

	void Camera::onDestroy()
	{
		Weak<Camera> cam = shared_from_this();
		//Camera::cameras.remove(cam);

		/*if (Camera::mainCam == shared_from_this())
		{
			if (Camera::cameras.size() > 0)
			{
				Camera::mainCam = (*Camera::cameras.begin()).lock();
			}
			else
			{
				Camera::mainCam = nullptr;
			}
		}*/
	}

	void Camera::onInitialize()
	{
		if (Camera::cameras.size() < 1)
		{
			setMainCam(shared_from_this());
		}
		Weak<Camera> cam = shared_from_this();
		AddCam(cam);
	}

	mat4 Camera::getProjection()
	{
		int w = 1920, h = 1080;
		if (getEntity())
		{
			getEntity()->getWindowSize(&w, &h);
		}
		return perspective(radians(FOV), (float)w/ (float)h, nearClip, farClip);
	}

	mat4 Camera::getView()
	{
		glm::mat4 viewMat;
		Shared<Transform> trans = getEntity()->getTransform();
		viewMat = mat4_cast(-trans->getRotationQuat());
		viewMat = translate(viewMat, -trans->getPosition());
		return viewMat;
	}
}