#include "PhysTransform.h"
#include "GLMWrapping.h"
#include <iostream>

namespace PhysB
{
	PhysTransform::PhysTransform()
	{
		position = glm::vec3();
		rotation = glm::quat();
	}

	void PhysTransform::initialise(glm::vec3 _pos)
	{
		position = _pos;
		std::cout << "Phys Transform Init" << std::endl;
	}

	mat4 PhysTransform::getModelMat()
	{
		mat4 translationMat = glm::translate(translationMat, position);
		mat4 rotationMat = mat4_cast(rotation);
		mat4 scaleMat = glm::scale(scaleMat, scale);

		return (translationMat * rotationMat * scaleMat);
	}

	void PhysTransform::Tick()
	{
		//std::cout << "Phys Transform Tick" << std::endl;
		//std::cout << position.z << std::endl;
	}

}