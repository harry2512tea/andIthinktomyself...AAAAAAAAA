#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <memory>
#include <list>
#include <GL/glew.h>
#include <rend/rend.h>

#define Shared std::shared_ptr
#define Weak std::weak_ptr

namespace ThomasTheTank
{
	class Entity;

	struct Camera;

	class Core
	{
	public:
		static Shared<Core> Initialise();
		void start();
		void stop();

		Shared<Entity> addEntity();
		void getWindowSize(int* w, int* h) { SDL_GetWindowSize(m_window, w, h); };
		//Weak<Camera> getMainCam() { return mainCam; };
		//void setMainCam(Shared<Camera> _cam) { mainCam = _cam; };
	private:

		//Shared<Camera> mainCam;
		SDL_Window* m_window;
		SDL_GLContext m_context;
		std::list<Shared<Entity>> m_entities;
		bool m_running = false;
		Weak<Core> m_self;
	};
}