#ifndef PHYSB_PHYSTIME_H
#define PHYSB_PHYSTIME_H

namespace PhysB
{
	struct PhysTime
	{
		static float DeltaTime() { return deltaTime; };

	private:
		friend struct PhysicsWorld;
		void tick(float idealTime, bool MT);
		void initialize();
		static float deltaTime;
		float lastTime;
	};
}

#endif // !PHYSB_PHYSTIME_H
