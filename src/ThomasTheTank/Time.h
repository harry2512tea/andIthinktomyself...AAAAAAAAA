#ifndef THOMASTHETANK_TIME_H
#define THOMASTHETANK_TIME_H

#include <memory>

#define Shared std::shared_ptr
#define Weak std::weak_ptr

namespace ThomasTheTank
{

	class SceneTime
	{
	public:
		static float DeltaTime() { return deltaTime; };

	private:
		friend class Core;
		void tick();
		void initialize();
		static float deltaTime;
		float lastTime;
		Weak<SceneTime> m_self;
	};
}
#endif