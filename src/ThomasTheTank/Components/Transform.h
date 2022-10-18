#ifndef THOMASTHETANK_TRANSFORM_H
#define THOMASTHETANK_TRANSFORM_H

#include "Wrapping/ThomasMath.h"
#include "Component.h"

namespace ThomasTheTank
{
	struct Transform : Component
	{
	public:
		void setPosition(vec3 pos) { position = pos; };
		void setRotation(vec3 rot) { rotation = rot; };
		void setScale(vec3 _scale) { scale = _scale; };

		void rotate(vec3 rot) { rotation += rot; };
		void translate(vec3 translation) { position += translation; };

		vec3 getPosition() { return position; };
		vec3 getRotation() { return rotation; };
		vec3 getScale() { return scale; };

	private:
		vec3 position = vec3(0.0f);
		vec3 rotation = vec3(0.0f);
		vec3 scale = vec3(0.0f);
	};
}

#endif