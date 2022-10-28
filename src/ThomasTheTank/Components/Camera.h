#ifndef THOMASTHETANK_CAMERA_H
#define THOMASTHETANK_CAMERA_H

//#include <rend/rend.h>
#include "ThomasTheTank/Wrapping/ThomasMath.h"
#include "../Component.h"
#include <memory>



namespace ThomasTheTank
{
	struct Camera : Component
	{
		mat4 getProjection();
		mat4 getView();
	private:
		float FOV = 70;
		float nearClip = 0.1f;
		float farClip = 1000;
	};
}

#endif