#include <memory>
//#include "glm/glm.hpp"
#include "GLMWrapping.h"

#define Shared std::shared_ptr
#define Weak std::weak_ptr
#define mkShared std::make_shared

namespace PhysB
{
	enum ForceMode
	{
		Impulse,
		VelocityChange
	};

	struct CollisionDet;
	struct PhysTransform;
	struct PhysicsWorld;
	struct PhysRigidBody
	{

		void AddForce(glm::vec3 force,  ForceMode _mode = Impulse);
		float getMass() { return mass; };
		void setMass(float _mass) { mass = _mass; };
		bool getUseGravity() { return gravity; };
		void setUseGravity(bool _gravity) { gravity = _gravity; };
		vec3 getVelocity() { return velocity; };
		void setVelocity(vec3 _vel) { velocity = _vel; };
		vec3 getAngularVelocity() { return angularVelocity; };
		void setAngularVelocity(vec3 _vel) { angularVelocity = _vel; };

	private:
		friend struct CollisionDet;
		void tick();
		bool gravity;
		float mass = 1.0f;
		glm::vec3 velocity = glm::vec3(0.0f);
		glm::vec3 angularVelocity = glm::vec3(0.0f);
		friend struct CollisionDet;
		Weak<PhysTransform> m_trans;
		Weak<CollisionDet> m_colDet;
	};
}