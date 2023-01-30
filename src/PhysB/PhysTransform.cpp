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

	void PhysTransform::Tick()
	{
		std::cout << "Phys Transform Tick" << std::endl;
	}

}