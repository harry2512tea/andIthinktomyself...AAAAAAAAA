#include "../Wrapping/ThomasMath.h"
#include "../Component.h"

namespace ThomasTheTank
{
	struct Transform;

	struct Collider : Component
	{
		Collider();

		void setOffset(vec3 _offset) { m_offset = _offset; };
		vec3 getOffset() { return m_offset; };
	protected:
		vec3 m_offset;
		Shared<Transform> m_trans;
	};
}