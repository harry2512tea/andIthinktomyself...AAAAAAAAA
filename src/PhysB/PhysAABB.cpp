#include "PhysAABB.h"
#include "PhysTransform.h"
#include <iostream>

namespace PhysB
{
	PhysAABB::PhysAABB()
	{
		vec3 min = getMin();
		vec3 max = getMax();
		//0, Top +ve Y normal
		Planes.push_back(std::make_shared<Plane>(vec3(max.x, max.y, min.z), vec3(min.x, max.y, max.z), vec3(max.x, max.y, max.z)));
		//1, Front +ve Z normal
		Planes.push_back(std::make_shared<Plane>(vec3(max.x, max.y, max.z), vec3(min.x, min.y, max.z), vec3(max.x, min.y, max.z)));
		//2, Right +ve X normal
		Planes.push_back(std::make_shared<Plane>(vec3(max.x, max.y, min.z), vec3(max.x, min.y, max.z), vec3(max.x, min.y, min.z)));
		//3, Back -ve Z normal
		Planes.push_back(std::make_shared<Plane>(vec3(min.x, max.y, min.z), vec3(max.x, min.y, min.z), vec3(min.x, min.y, min.z)));
		//4, Left -ve X normal
		Planes.push_back(std::make_shared<Plane>(vec3(min.x, max.y, max.z), vec3(min.x, min.y, min.z), vec3(min.x, min.y, max.z)));
		//5 Bottom -ve Y normal
		Planes.push_back(std::make_shared<Plane>(vec3(max.x, min.y, max.z), vec3(min.x, min.y, min.z), vec3(max.x, min.y, min.z)));

		//corner points of the box
		initialPoints.push_back(max);
		initialPoints.push_back(vec3(min.x, max.y, max.z));
		initialPoints.push_back(vec3(min.x, max.y, min.z));
		initialPoints.push_back(vec3(max.x, max.y, min.z));

		initialPoints.push_back(vec3(max.x, min.y, max.z));
		initialPoints.push_back(vec3(min.x, min.y, max.z));
		initialPoints.push_back(min);
		initialPoints.push_back(vec3(max.x, min.y, min.z));

		for (size_t I = 0; I < initialPoints.size(); I++)
		{
			points.push_back(initialPoints.at(I) * getSize());
		}

		colliderType = Box;

	}
	void PhysAABB::onTick()
	{
		for (size_t I = 0; I < Planes.size(); I++)
		{
			Planes.at(I)->UpdatePos(m_trans->getPosition(), getSize());
		}

		points.clear();
		for (size_t I = 0; I < initialPoints.size(); I++)
		{
			points.push_back(initialPoints.at(I) * getSize());
		}
	}
}