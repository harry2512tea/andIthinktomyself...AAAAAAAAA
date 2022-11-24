#include "../Wrapping/ThomasMath.h"
#include "../Component.h"

namespace ThomasTheTank
{
	struct Collider : Component
	{
		void setOffset(vec3 _offset);
		vec3 getOffset() { return m_offset; };
	protected:
		vec3 m_offset;
	};
}