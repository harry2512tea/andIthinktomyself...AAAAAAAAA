#include <pellet/btBulletDynamicsCommon.h>
#include <memory>

#define Shared std::shared_ptr
namespace ThomasTheTank
{
	struct Physics
	{
		Physics();
		Shared<btDiscreteDynamicsWorld> getPhysics() { return dynamicsWorld; };
		void addCollider(Shared<btCollisionShape> _shape);
	private:
		btDefaultCollisionConfiguration collisionConfiguration;
		btCollisionDispatcher dispatcher;
		btDbvtBroadphase overlappingPairCache;
		btSequentialImpulseConstraintSolver solver;
		Shared<btDiscreteDynamicsWorld> dynamicsWorld;

		btAlignedObjectArray<Shared<btCollisionShape>> collisionShapes;
	};
}