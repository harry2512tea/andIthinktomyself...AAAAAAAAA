#include <iostream>
#include "../Components/Transform.h"

namespace ThomasTheTank
{
	void Transform::onTick()
	{
		rotation = checkRoationValues(rotation);
	}


	quat Transform::generateRotQuat(vec3 _rotation)
	{
		quat x = glm::angleAxis(radians(_rotation.x), vec3(1.0f, 0.0f, 0.0f));
		quat y = glm::angleAxis(radians(_rotation.y), vec3(0.0f, 1.0f, 0.0f));
		quat z = glm::angleAxis(radians(_rotation.z), vec3(0.0f, 0.0f, 1.0f));
	
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
		mat4 rotationMat = mat4(1.0f);
		mat4 translationMat = mat4(1.0f);
		mat4 scaleMat = mat4(1.0f);


		translationMat = glm::translate(translationMat, position);
		rotationMat = mat4_cast(rotationQuat);
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