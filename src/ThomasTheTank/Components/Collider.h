#ifndef THOMASTHETANK_COLLIDER_H
#define THOMASTHETANK_COLLIDER_H

#include "../Wrapping/ThomasMath.h"
#include "../Component.h"
#include <PhysB/PhysB.h>

namespace ThomasTheTank
{
	struct Transform;

	struct Collider : Component, PhysB::CollisionEvent
	{
		/**
		* Set the offset of the collider
		* 
		* \param _offset VEC3 the new offset.
		*/
		void setOffset(vec3 _offset) { m_offset = _offset; };

		/**
		* Get the offset of the collider
		*
		* \return VEC3 the offset.
		*/
		vec3 getOffset() { return m_offset; };
		
	protected:
		friend struct RigidBody;
		vec3 m_offset; ///< offset from the center point of its transform
		Shared<Transform> m_trans; ///< link to the collider's transform
		Weak<PhysB::PhysRigidBody> m_body; ///< link to the corresponding rigidbody in the physics world.
	private:
		friend struct Entity;
		virtual void onAddRigidBody(Shared<PhysB::PhysRigidBody> _body); ///< Function called when adding a rigidbody reference.
		virtual void onRemoveRigidBody(); ///< Function called when removing a rigidbody reference.
		/**
		* Function to set the rigidbody reference in the collider.
		*
		* \param _body Shared<PhysB::PhysRigidBody> shared pointer reference to the physics library's rigidbody component.
		*/
		void AddRigidBody(Shared <PhysB::PhysRigidBody> _body);
		void RemoveRigidBody(); ///< Function to remove the rigidbody reference in the collider.
		void onInitialize(); ///< Function called on creation of the collider.
		void onTick(); ///< Function called every frame.
		void onDestroy(); ///< Function called on destruction of the collider
		/**
		* Function called when the physics world detects the collider is entering a collision.
		* 
		* \param collision Shared<CollisionInfo> Shraed pointer reference to collision information struct.
		*/
		void physOnCollisionEnter(Shared<CollisionRet> collision);
		/**
		* Function called when the physics world detects the collider is exiting a collision.
		*
		* \param collision Shared<CollisionInfo> Shraed pointer reference to collision information struct.
		*/
		void physOnCollisionExit(Shared<CollisionRet> collision);
		/**
		* Function called when the physics world detects the collider is still inside a collision.
		*
		* \param collision Shared<CollisionInfo> Shraed pointer reference to collision information struct.
		*/
		void physOnCollisionStay(Shared<CollisionRet> collision);
		/**
		* Function called when the physics world detects the collider is entering a trigger.
		*
		* \param collision Shared<CollisionInfo> Shraed pointer reference to collision information struct.
		*/
		void physOnTriggerEnter(Shared<CollisionRet> collision);
		/**
		* Function called when the physics world detects the collider is exiting a trigger.
		*
		* \param collision Shared<CollisionInfo> Shraed pointer reference to collision information struct.
		*/
		void physOnTriggerExit(Shared<CollisionRet> collision);
		/**
		* Function called when the physics world detects the collider is still inside a trigger.
		*
		* \param collision Shared<CollisionInfo> Shraed pointer reference to collision information struct.
		*/
		void physOnTriggerStay(Shared<CollisionRet> collision);
	};
}
#endif // !THOMASTHETANK_COLLIDER_H