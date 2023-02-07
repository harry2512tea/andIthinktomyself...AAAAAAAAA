#ifndef THOMASTHETANK_BOXCOLLIDER_H
#define THOMASTHETANK_BOXCOLLIDER_H

#include "../../Wrapping/ThomasMath.h"
#include "../Collider.h"
#include <memory>
#include <PhysB/PhysB.h>

#define Shared std::shared_ptr
#define Weak std::weak_ptr

namespace ThomasTheTank
{
	struct Transform;

	struct BoxCollider : Collider
	{

	protected:
		void onInitialize(); ///< Function called on creation of the collider
		void onTick(); ///< Function called every frame
		/*
		* Function to set the rigidbody reference in the collider.
		* 
		* \param _body Shared<PhysB::PhysRigidBody> shared pointer reference to the physics library's rigidbody component.
		*/
		void onAddRigidBody(Shared<PhysB::PhysRigidBody> _body);
		void onRemoveRigidBody(); ///< Function to remove the rigidbody reference in the collider.
		vec3 size; ///< Size of the collider component.
		Weak<PhysB::PhysAABB> m_collider; ///< Reference to the corresponding physics library's collider.
	};
}
#endif // !THOMASTHETANK_BOXCOLLIDER_H