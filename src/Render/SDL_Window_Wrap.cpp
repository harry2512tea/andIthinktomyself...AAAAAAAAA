#include "SDL_Window_Wrap.h"

namespace Render
{
	Shared<Render::SDLWindow> Render::SDLWindow::Initialise()
	{
		Shared<Render::SDLWindow> rtn = std::make_shared<Render::SDLWindow>();
		rtn->m_self = rtn;

		return rtn;
	}

	SDL_Window* Render::SDLWindow::GenerateWindow(int width, int height)
	{
		m_window = SDL_CreateWindow("ThomasTheTank",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			width, height, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

		return m_window;
	}
	SDL_Window* Render::SDLWindow::GetWindow()
	{
		return m_window;
	}
}