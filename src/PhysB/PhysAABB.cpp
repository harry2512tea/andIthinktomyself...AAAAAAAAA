#include "PhysAABB.h"

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
		points.push_back(max);
		points.push_back(vec3(min.x, max.y, max.z));
		points.push_back(vec3(min.x, max.y, min.z));
		points.push_back(vec3(max.x, max.y, min.z));

		points.push_back(vec3(max.x, min.y, max.z));
		points.push_back(vec3(min.x, min.y, max.z));
		points.push_back(min);
		points.push_back(vec3(max.x, min.y, min.z));

	}
}