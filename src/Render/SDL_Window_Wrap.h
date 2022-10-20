#include <stdexcept>
#include <iostream>
#include <SDL2/SDL.h>
#include <memory>

#define Shared std::shared_ptr
#define Weak std::weak_ptr

namespace Render
{

	struct SDLWindow
	{
		static Shared<SDLWindow> Initialise();
		SDL_Window* GenerateWindow(int width, int height);
		SDL_Window* GetWindow();
	private:
		SDL_Window* m_window;
		Weak<SDLWindow> m_self;
	};
}