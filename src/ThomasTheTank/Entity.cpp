#include "Entity.h"
#include "Component.h"
#include "Core.h"
#include "Components/Collider.h"
#include "Components/RigidBody.h"
#include "Exceptions.h"

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
			if ((*it)->enabled)
			{
				try
				{
					(*it)->tick();
				}
				catch (Exception& e)
				{
					std::cout << "Exception: " << e.what() << std::endl;
					(*it)->enabled = false;
				}
				catch (...)
				{
					std::cout << "An unknown exception was thrown" << std::endl;
					(*it)->enabled = false;
				}
			}
		}
	}

	void Entity::lateTick()
	{
		for (std::list<Shared<Component>>::iterator it = m_components.begin(); it != m_components.end(); it++)
		{
			if ((*it)->enabled)
			{
				try
				{
					(*it)->lateTick();
				}
				catch (Exception& e)
				{
					std::cout << "Exception: " << e.what() << std::endl;
					(*it)->enabled = false;
				}
				catch (...)
				{
					std::cout << "An unknown exception was thrown" << std::endl;
					(*it)->enabled = false;
				}
			}
		}
	}

	void Entity::display()
	{
		for (std::list<Shared<Component>>::iterator it = m_components.begin(); it != m_components.end(); it++)
		{
			if ((*it)->enabled)
			{
				try
				{
					(*it)->display();
				}
				catch (Exception& e)
				{
					std::cout << "Exception: " << e.what() << std::endl;
					(*it)->enabled = false;
				}
				catch (...)
				{
					std::cout << "An unknown exception was thrown" << std::endl;
					(*it)->enabled = false;
				}
			}
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
	void Entity::collisionEnter(Shared<PhysB::CollisionRet> collision)
	{
		for (std::list<Shared<Component>>::iterator it = m_components.begin(); it != m_components.end(); it++)
		{
			(*it)->collisionEnter(collision);
		}
	}
	void Entity::collisionExit(Shared<PhysB::CollisionRet> collision)
	{
		for (std::list<Shared<Component>>::iterator it = m_components.begin(); it != m_components.end(); it++)
		{
			(*it)->collisionExit(collision);
		}
	}
	void Entity::collisionStay(Shared<PhysB::CollisionRet> collision)
	{
		for (std::list<Shared<Component>>::iterator it = m_components.begin(); it != m_components.end(); it++)
		{
			(*it)->collisionStay(collision);
		}
	}
	void Entity::triggerEnter(Shared<PhysB::CollisionRet> collision)
	{
		for (std::list<Shared<Component>>::iterator it = m_components.begin(); it != m_components.end(); it++)
		{
			(*it)->triggerEnter(collision);
		}
	}
	void Entity::triggerExit(Shared<PhysB::CollisionRet> collision)
	{
		for (std::list<Shared<Component>>::iterator it = m_components.begin(); it != m_components.end(); it++)
		{
			(*it)->triggerExit(collision);
		}
	}
	void Entity::triggerStay(Shared<PhysB::CollisionRet> collision)
	{
		for (std::list<Shared<Component>>::iterator it = m_components.begin(); it != m_components.end(); it++)
		{
			(*it)->triggerStay(collision);
		}
	}
}