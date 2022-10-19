#include <iostream>
#include "../Components/Transform.h"

namespace ThomasTheTank
{
	void Transform::onTick()
	{
		
	}


	quat Transform::generateRotQuat(vec3 _rotation)
	{
		glm::quat x = glm::angleAxis(radians(_rotation.x), vec3(1.0f, 0.0f, 0.0f));
		glm::quat y = glm::angleAxis(radians(_rotation.y), vec3(0.0f, 1.0f, 0.0f));
		glm::quat z = glm::angleAxis(radians(_rotation.z), vec3(0.0f, 0.0f, 1.0f));

		return x * y * z;
	}

	void Transform::setRotation(vec3 _rotation)
	{
		rotationQuat = generateRotQuat(_rotation);
	}

	void Transform::rotate(vec3 _rotation)
	{
		rotationQuat *= generateRotQuat(_rotation);
	}
}