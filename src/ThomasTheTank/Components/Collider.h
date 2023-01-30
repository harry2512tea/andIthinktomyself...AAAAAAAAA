#ifndef THOMASTHETANK_COLLIDER_H
#define THOMASTHETANK_COLLIDER_H



#include "../Wrapping/ThomasMath.h"
#include "../Component.h"

namespace ThomasTheTank
{
	struct Transform;

	struct Collider : Component
	{

		void setOffset(vec3 _offset) { m_offset = _offset; };
		vec3 getOffset() { return m_offset; };
	protected:
		vec3 m_offset;
		Shared<Transform> m_trans;
	private:
		void onInitialize();
		void onTick();
		void onDestroy();
	};
}
#endif // !THOMASTHETANK_COLLIDER_H