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
	/** \mainpage notitle
	* The official documentation regarding the ThomasTheTank game engine.
	*/
	class Entity;

	struct Camera;

	struct Input;

	class SceneTime;

	/**
	* Main class of the game engine.
	*/
	class Core
	{
	public:
		/**
		*Initialise the game engine and create an instance of Core.
		* 
		* \return Pointer to the Core class.
		*/
		static Shared<Core> Initialise();
		void start(); ///< Start the main loop of the engine.
		void stop(); ///< Close the program.

		/**
		* Add an empty entity to the scene.
		* 
		* \return Pointer to the new entity.
		*/
		Shared<Entity> addEntity();
		/**
		* Get size of the window.
		* 
		* \param INT w Pointer to output variable for width.
		* \param INT h Pointer to output variable for height.
		*/
		void getWindowSize(int* w, int* h) { SDL_GetWindowSize(m_window, w, h); };

	private:
		void eventManager();

		Shared<Input> input; ///< Pointer to the input manager class.
		SDL_Window* m_window; ///< The window of the program
		SDL_GLContext m_context; ///< OpenGL context
		std::list<Shared<Entity>> m_entities; ///< List of every entity in the scene
		Shared<SceneTime> environment; ///< Pointer to the environment manager class
		bool m_running = false; ///< Current state of the program
		Weak<Core> m_self; ///< Pointer to self
	};
}