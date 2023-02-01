#ifndef PHYSB_PHYSAABB_H
#define PHYSB_PHYSAABB_H

#include "GLMWrapping.h"
#include "PhysB/Collider.h"

namespace PhysB
{
	struct PhysAABB : PhysCollider
	{
		vec3 getMin() { return m_min; };
		vec3 getMax() { return m_max; };
		void setMin(vec3(_min)) { m_min = _min; };
		void setMax(vec3(_max)) { m_max = _max; };

	private:
		vec3 m_min = vec3(-0.5f), m_max = vec3(0.5f);
	};

}

#endif // !PHYSB_PHYSAABB_H