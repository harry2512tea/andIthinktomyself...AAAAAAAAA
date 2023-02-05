#include "Physics.h"
#include "CollisionDet.h"
#include "PhysRigidBody.h"
#include "PhysTransform.h"
#include "Collider.h"
#include <SDL2/SDL.h>
#include <iostream>

namespace PhysB
{
	Shared<PhysicsWorld> PhysicsWorld::initialise(bool &_running, bool _multiThreaded)
	{
		Shared<PhysicsWorld> rtn = mkShared<PhysicsWorld>();

		rtn->collisonDetection = mkShared<CollisionDet>();
		rtn->Gravity = vec3(0.0f, -9.81f, 0.0f);
		rtn->m_running = &_running;
		rtn->multiThreaded = _multiThreaded;
		rtn->m_self = rtn;
		std::cout << "physics world initialised" << std::endl;
		return rtn;
	}

	Shared<PhysRigidBody> PhysicsWorld::AddRigidBody(Shared<PhysTransform> _trans)
	{
		return collisonDetection->AddRigidBody(_trans);
	}

	Shared <PhysTransform> PhysicsWorld::AddTransform()
	{
		return collisonDetection->AddTransform();
	}

	void PhysicsWorld::Start()
	{
		if (multiThreaded)
		{
			while (m_running)
			{
				Tick();
			}
		}
	}

	void PhysicsWorld::Tick()
	{
		collisonDetection->Tick();
		//std::cout << "Physics World Tick" << std::endl;
	}
}