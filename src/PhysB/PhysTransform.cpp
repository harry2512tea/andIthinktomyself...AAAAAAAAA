#include "PhysTransform.h"


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
	}

}