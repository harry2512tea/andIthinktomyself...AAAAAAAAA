#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <memory>
#include <list>
#include <GL/glew.h>
#include <rend/rend.h>
//#include <Render/SDL_Window_Wrap.h>

#define Shared std::shared_ptr
#define Weak std::weak_ptr

namespace ThomasTheTank
{
	class Entity;

	class Core
	{
	public:
		static Shared<Core> Initialise();
		void start();
		void stop();

		Shared<Entity> addEntity();


	private:
		//Shared<Render::SDLWindow> SDLwindow = Render::SDLWindow::Initialise();
		SDL_Window* m_window;
		SDL_GLContext m_context;
		std::list<Shared<Entity>> m_entities;
		bool m_running = false;
		Weak<Core> m_self;
	};
}