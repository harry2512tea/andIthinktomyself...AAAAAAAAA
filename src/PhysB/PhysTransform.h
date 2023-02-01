//#include <glm/glm.hpp>
//#include <glm/ext.hpp>
#include <memory>
#include "GLMWrapping.h"

#define Shared std::shared_ptr
#define Weak std::weak_ptr
#define mkShared std::make_shared

namespace PhysB
{
	struct PhysRigidBody;
	struct CollisionDet;

	struct PhysTransform
	{
		PhysTransform();
		
		void initialise(glm::vec3 _pos);
		void setPosition(glm::vec3 _pos) { position = _pos; };
		void Translate(glm::vec3 _translation) { position += _translation; };
		void Rotate(glm::vec3 _rotation) { rotation *= glm::quat(_rotation); };
		void Rotate(glm::quat _rotation) { rotation *= _rotation; };
		void setRotation(glm::vec3 _rotation) { rotation = glm::quat(_rotation); };
		void setRotation(glm::quat _rotation) { rotation = _rotation; };
		glm::vec3 getPosition() { return position; };
		glm::vec3 eulerAngles() { return glm::degrees(glm::eulerAngles(rotation)); };
		glm::quat getRotation() { return rotation; };

	private:
		friend struct CollisionDet;
		void Tick();
		bool dynamic = false;
		glm::vec3 position;
		glm::quat rotation;
		Weak<PhysRigidBody> m_body;

	};
}