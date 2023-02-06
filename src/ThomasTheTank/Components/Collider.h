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

		void setOffset(vec3 _offset) { m_offset = _offset; };
		vec3 getOffset() { return m_offset; };
		
	protected:
		friend struct RigidBody;
		vec3 m_offset;
		Shared<Transform> m_trans;
		Weak<PhysB::PhysRigidBody> m_body;
	private:
		friend struct Entity;
		virtual void onAddRigidBody(Shared<PhysB::PhysRigidBody> _body);
		virtual void onRemoveRigidBody();
		void AddRigidBody(Shared <PhysB::PhysRigidBody> _body);
		void RemoveRigidBody();
		void onInitialize();
		void onTick();
		void onDestroy();
		void physOnCollisionEnter(Shared<CollisionInfo> collision);
		void physOnCollisionExit(Shared<CollisionInfo> collision);
		void physOnCollisionStay(Shared<CollisionInfo> collision);
		void physOnTriggerEnter(Shared<CollisionInfo> collision);
		void physOnTriggerExit(Shared<CollisionInfo> collision);
		void physOnTriggerStay(Shared<CollisionInfo> collision);
	};
}
#endif // !THOMASTHETANK_COLLIDER_H