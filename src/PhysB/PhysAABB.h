#ifndef PHYSB_PHYSAABB_H
#define PHYSB_PHYSAABB_H

#include "GLMWrapping.h"
#include "PhysB/Collider.h"
#include <vector>

namespace PhysB
{
	struct PhysAABB : PhysCollider
	{
		PhysAABB();

	private:
		friend struct CollisionDet;
		friend struct Collisions;
		void onTick();
		std::vector<Shared<Plane>> Planes;
		std::vector<vec3> points;
		std::vector<vec3> initialPoints;
	};

}

#endif // !PHYSB_PHYSAABB_H