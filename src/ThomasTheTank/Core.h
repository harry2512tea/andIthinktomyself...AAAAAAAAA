#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <memory>
#include <list>
#include <GL/glew.h>
#include <rend/rend.h>
#include <AL/al.h>
#include <AL/alc.h>
#include <pellet/btBulletDynamicsCommon.h>

#define Shared std::shared_ptr
#define Weak std::weak_ptr

namespace ThomasTheTank
{
	/** \mainpage notitle
	* The official documentation regarding the ThomasTheTank game engine.
	*/
	struct Entity;

	struct Camera;

	struct Input;

	struct SceneTime;

	struct Physics;

	/**
	* Main struct of the game engine.
	*/
	struct Core
	{
	public:
		/**
		*Initialise the game engine and create an instance of Core.
		* 
		* \return Pointer to the Core struct.
		*/
		static Shared<Core> Initialise();
		//Core();
		void start(); ///< Start the main loop of the engine.
		void stop(); ///< Close the program.

		/**
		* Add an empty entity to the scene.
		* 
		* \return Pointer to the new entity.
		*/
		Shared<Entity> addEntity();
		Shared<Physics> getPhysics() { return m_Physics; };
		/**
		* Get size of the window.
		* 
		* \param INT w Pointer to output variable for width.
		* \param INT h Pointer to output variable for height.
		*/
		void getWindowSize(int* w, int* h) { SDL_GetWindowSize(m_window, w, h); };

	private:
		void eventManager();

		ALCdevice* device;
		ALCcontext* context;

		Shared<Physics> m_Physics;

		Shared<Input> input; ///< Pointer to the input manager struct.
		SDL_Window* m_window; ///< The window of the program
		SDL_GLContext m_context; ///< OpenGL context
		std::list<Shared<Entity>> m_entities; ///< List of every entity in the scene
		Shared<SceneTime> environment; ///< Pointer to the environment manager struct
		bool m_running = false; ///< Current state of the program
		Weak<Core> m_self; ///< Pointer to self
	};
}