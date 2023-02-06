#include "PhysTime.h"
#include <SDL2/SDL.h>

namespace PhysB
{
	float PhysTime::deltaTime = 0;
	void PhysTime::initialize()
	{
		lastTime = SDL_GetTicks();
	}
	void PhysTime::tick(float idealTime, bool MT)
	{
		float time = SDL_GetTicks();
		float diff = time - lastTime;
		deltaTime = diff / 1000.0f;
		lastTime = time;

		if (idealTime > deltaTime && MT)
		{
			SDL_Delay((idealTime - deltaTime) * 1000.0f);
			deltaTime = idealTime;
		}
	}

	
}