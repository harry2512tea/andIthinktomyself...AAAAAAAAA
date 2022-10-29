#include "Time.h"
#include "Core.h"
#include <SDL2/SDL.h>

namespace ThomasTheTank
{

	float SceneTime::deltaTime = 0;

	void SceneTime::initialize()
	{
		lastTime = SDL_GetTicks();
	}

	void SceneTime::tick()
	{
		float time = SDL_GetTicks();
		float diff = time - lastTime;
		deltaTime = diff / 1000.0f;
		lastTime = time;

		float idealTime = 1.0f / 65.0f;

		if (idealTime > deltaTime)
		{
			SDL_Delay((idealTime - deltaTime) * 1000.0f);
			deltaTime = idealTime;
		}
	}
}