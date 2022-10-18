#ifndef THOMASTHETANK_TRANSFORM_H
#define THOMASTHETANK_TRANSFORM_H

#include "Wrapping/ThomasMath.h"

namespace ThomasTheTank
{
	class Transform : Component
	{
	public:
	private:
		vec3 position;
		vec3 rotation;
		vec3 scale;
	};
}

#endif