#ifndef PHYSB_PHYSICS_H
#define PHYSB_PHYSICS_H

#include <memory>
#include <vector>
//#include <glm/glm.hpp>
#include "GLMWrapping.h"

#define Shared std::shared_ptr
#define Weak std::weak_ptr
#define mkShared std::make_shared
using namespace glm;

namespace PhysB
{
	struct PhysRigidBody;

	struct CollisionDet;

	struct PhysCollider;

	struct PhysTransform;

	struct PhysTime;

	struct PhysicsWorld
	{
		static Shared<PhysicsWorld> initialise(bool& _running, bool _multiThreaded);

		void Start();
		void Tick();
		void setGravity(vec3 _grav) { Gravity = _grav; };
		vec3 getGravity() { return Gravity; };

		template<typename T>
		Shared<T> AddCollider(Shared<PhysTransform> _trans)
		{
			Shared<T> rtn = mkShared<T>();
			rtn->m_trans = _trans;
			rtn->ID = collisonDetection->Colliders.size();
			collisonDetection->AddCollider(rtn);
			return rtn;
		}

		Shared<PhysRigidBody> AddRigidBody(Shared<PhysTransform> _trans);
		Shared<PhysTransform> AddTransform();

	private:
		float stepTime = 200;
		Shared<CollisionDet> collisonDetection;
		bool* m_running = false;
		bool multiThreaded = false;
		vec3 Gravity = vec3(0.0f, -9.81f, 0.0f);
		Weak<PhysicsWorld> m_self;
		Shared<PhysTime> m_time;

	};
}
#endif // !PHYSB_PHYSICS_H
