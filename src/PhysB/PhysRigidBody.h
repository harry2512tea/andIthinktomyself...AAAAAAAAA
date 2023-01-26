#include <memory>
#include "glm/glm.hpp"

#define Shared std::shared_ptr
#define Weak std::weak_ptr
#define mkShared std::make_shared

namespace PhysB
{
	struct CollisionDet;
	struct PhysTransform;
	struct PhysRigidBody
	{
		void tick();
	private:
		glm::vec3 velocity;
		friend struct CollisionDet;
		Weak<PhysTransform> m_trans;
	};
}