#ifndef THOMASTHETANK_RIGIDBODY_H
#define THOMASTHETANK_RIGIDBODY_H

#include <memory>
#include <PhysB/PhysB.h>
#include "../Component.h"

namespace ThomasTheTank
{
	struct RigidBody : Component
	{
		void AddForce(glm::vec3 force, PhysB::ForceMode _mode = PhysB::Impulse);
		float getMass();
		void setMass(float _mass);
		bool getUseGravity();;
		void setUseGravity(bool _gravity);
		vec3 getVelocity();
		void setVelocity(vec3 _vel);
		vec3 getAngularVelocity();
		void setAngularVelocity(vec3 _vel);
		float getElasticity();
		void setElasticity(float _elasticity);
		float getFriction();
		void setFriction(float _friction);

	private:
		void onInitialize();
		void onDestroy();
		Shared<PhysB::PhysRigidBody> m_body;
	};
}
#endif // !THOMASTHETANK_RIGIDBODY_H