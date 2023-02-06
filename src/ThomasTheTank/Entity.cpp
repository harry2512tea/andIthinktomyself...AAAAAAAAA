#include "Entity.h"
#include "Component.h"
#include "Core.h"
#include "Components/Collider.h"
#include "Components/RigidBody.h"

namespace ThomasTheTank
{
	void Entity::kill()
	{
		if (!m_alive) return;

		m_alive = false;

		for (std::list<Shared<Component>>::iterator it = m_components.begin(); it != m_components.end(); it++)
		{
			(*it)->kill();
		}
	}

	void Entity::getWindowSize(int* w, int* h)
	{
		m_core.lock()->getWindowSize(w, h);
	}

	void Entity::tick()
	{
		for (std::list<Shared<Component>>::iterator it = m_components.begin(); it != m_components.end(); it++)
		{
			(*it)->tick();
		}
	}

	void Entity::lateTick()
	{
		for (std::list<Shared<Component>>::iterator it = m_components.begin(); it != m_components.end(); it++)
		{
			(*it)->lateTick();
		}
	}

	void Entity::display()
	{
		for (std::list<Shared<Component>>::iterator it = m_components.begin(); it != m_components.end(); it++)
		{
			(*it)->display();
		}
	}

	void Entity::addRigidBody(Shared<PhysB::PhysRigidBody> body)
	{
		for (size_t I = 0; I < m_colliders.size(); I++)
		{
			m_colliders.at(I).lock()->AddRigidBody(body);
		}
	}

	void Entity::removeRigidBody()
	{
		for (size_t I = 0; I < m_colliders.size(); I++)
		{
			m_colliders.at(I).lock()->RemoveRigidBody();
		}
	}

	void Entity::initialize()
	{
		for (std::list<Shared<Component>>::iterator it = m_components.begin(); it != m_components.end(); it++)
		{
			(*it)->initialize();
		}
	}

	void Entity::destroy()
	{
		for (std::list<Shared<Component>>::iterator it = m_components.begin(); it != m_components.end(); it++)
		{
			(*it)->destroy();
		}
	}
	void Entity::collisionEnter(Shared<CollisionInfo> collision)
	{
		for (std::list<Shared<Component>>::iterator it = m_components.begin(); it != m_components.end(); it++)
		{
			(*it)->collisionEnter(collision);
		}
	}
	void Entity::collisionExit(Shared<CollisionInfo> collision)
	{
		for (std::list<Shared<Component>>::iterator it = m_components.begin(); it != m_components.end(); it++)
		{
			(*it)->collisionExit(collision);
		}
	}
	void Entity::collisionStay(Shared<CollisionInfo> collision)
	{
		for (std::list<Shared<Component>>::iterator it = m_components.begin(); it != m_components.end(); it++)
		{
			(*it)->collisionStay(collision);
		}
	}
}