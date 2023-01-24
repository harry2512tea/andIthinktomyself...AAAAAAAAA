#include "Collider.h"
#include "../Entity.h"
#include "Transform.h"


namespace ThomasTheTank
{
	Collider::Collider()
	{
		m_trans = getEntity()->getTransform();
	}
}