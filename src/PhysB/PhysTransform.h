#include <glm/glm.hpp>
#include <glm/ext.hpp>

namespace PhysB
{
	struct PhysTransform
	{
		PhysTransform();
		void initialise(glm::vec3 _pos);
		void setPosition(glm::vec3 _pos) { position = _pos; };
		void Translate(glm::vec3 _translation) { position += _translation; };
		glm::vec3 getPosition() { return position; };

	private:
		glm::vec3 position;
		glm::quat rotation;
	};
}