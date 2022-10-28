#include <iostream>
#include "../Components/Transform.h"

namespace ThomasTheTank
{
	void Transform::onTick()
	{
		rotation = checkRoationValues(rotation);
		//rotate(vec3(0.0f, rotationSpeed, 0.0f));
		//rotationSpeed += 0.1f;
		//position = vec3(0.0f, 0.0f, 10.0f);
		//scale = vec3(1.0f, 1.0f, 1.0f);
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

	mat4 Transform::getModel()
	{
		glm::mat4 rotationMat = glm::mat4(1.0f);
		glm::mat4 translationMat = glm::mat4(1.0f);
		glm::mat4 scaleMat = glm::mat4(1.0f);


		translationMat = glm::translate(translationMat, position);
		rotationMat = glm::mat4_cast(rotationQuat);
		scaleMat = glm::scale(scaleMat, scale);
		
		return translationMat * rotationMat * scaleMat;
	}

	vec3 Transform::checkRoationValues(vec3 _rot)
	{
		if (_rot.x > 360)
		{
			_rot.x -= 360;
		}
		else if (_rot.x < -360)
		{
			_rot.x += 360;
		}
		if (_rot.y > 360)
		{
			_rot.y -= 360;
		}
		else if (_rot.y < -360)
		{
			_rot.y += 360;
		}
		if (_rot.z > 360)
		{
			_rot.z -= 360;
		}
		else if (_rot.z < -360)
		{
			_rot.z += 360;
		}

		return _rot;
	}
}