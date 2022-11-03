#ifndef THOMASTHETANK_TRANSFORM_H
#define THOMASTHETANK_TRANSFORM_H

#include "../Wrapping/ThomasMath.h"
#include "../Component.h"

namespace ThomasTheTank
{
	/**
	* Component containing information about the state of the entity
	*/
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
		quat getRotationQuat() { return rotationQuat; };
		vec3 getScale() { return scale; };

		mat4 getModel();

	private:
		quat generateRotQuat(vec3 _rotation);
		void onTick();

		vec3 position = vec3(0.0f); ///< X, Y, Z location of the Entity
		vec3 rotation = vec3(0.0f); ///
		vec3 scale = vec3(1.0f);
		quat rotationQuat = quat();

		float rotationSpeed = 0.1f;

		vec3 checkRoationValues(vec3 _rot);
	};
}

#endif