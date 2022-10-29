#ifndef THOMASTHETANK_CAMERA_H
#define THOMASTHETANK_CAMERA_H

//#include <rend/rend.h>
#include "ThomasTheTank/Wrapping/ThomasMath.h"
#include "../Component.h"
#include <memory>
#include <list>


namespace ThomasTheTank
{
	struct Camera : Component, std::enable_shared_from_this<Camera>
	{
		//~Camera();
		mat4 getProjection();
		mat4 getView();
		static Shared<Camera> main();
		void setMainCam(Shared<Camera> newMain) { mainCam = newMain; };
	private:
		void onInitialize();
		void onDestroy();
		static Shared<Camera> mainCam;
		static std::list<Weak<Camera>> cameras;
		void AddCam(Weak<Camera> cam) { Camera::cameras.push_back(cam); };
		float FOV = 70;
		float nearClip = 0.1f;
		float farClip = 1000;
	};
}

#endif