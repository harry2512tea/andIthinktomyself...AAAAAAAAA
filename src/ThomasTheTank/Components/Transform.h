#ifndef THOMASTHETANK_TRANSFORM_H
#define THOMASTHETANK_TRANSFORM_H

#include "ThomasTheTank/Wrapping/ThomasMath.h"
#include "ThomasTheTank/Component.h"

namespace ThomasTheTank
{
	struct Transform : Component
	{
	public:
		void setPosition(vec3 pos) { position = pos; };
		void setRotation(vec3 rot);
		void setScale(vec3 _scale) { scale = _scale; };

		void rotate(vec3 rot);
		void translate(vec3 translation) { position += translation; };

		vec3 getPosition() { return position; };
		vec3 getRotation() { return rotation; };
		vec3 getScale() { return scale; };

	private:
		quat generateRotQuat(vec3 _rotation);
		void onTick();

		vec3 position = vec3(0.0f);
		vec3 rotation = vec3(0.0f);
		vec3 scale = vec3(0.0f);
		quat rotationQuat = quat();
	};
}

#endif