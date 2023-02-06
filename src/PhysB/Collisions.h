#ifndef PHYSB_COLLISIONS_H
#define PHYSB_COLLISIONS_H

#include "GLMWrapping.h"
#include <memory>
#include <vector>

#define Shared std::shared_ptr
#define Weak std::weak_ptr
#define mkShared std::make_shared

namespace PhysB
{

	struct PhysCollider;

	struct CollisionInfo;

	struct Axis
	{
		float minProj, maxProj;
		vec3 normal;
	};

	struct Collisions
	{
		Shared<CollisionInfo> CheckCollision(Shared<PhysCollider> Col1, Shared<PhysCollider> Col2);
		void BoxBox(Shared<CollisionInfo> colInfo);
		Axis projOntoAxis(std::vector<vec3> points, vec3 normal);
		void BoxBoxColPoint(Shared<CollisionInfo> colInfo);

		void CheckResponse(Shared<CollisionInfo> colInfo);
		void BoxBoxResponse(Shared<CollisionInfo> colInfo);
	};

}
#endif