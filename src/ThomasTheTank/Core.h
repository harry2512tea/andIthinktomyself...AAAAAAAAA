#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <memory>
#include <list>
#include <GL/glew.h>
//#include <rend/rend.h>
#include <AL/al.h>
#include <AL/alc.h>
#include <PhysB/PhysB.h>

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

	struct Cache;

	struct SceneTime;

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

		/**
		* Get a link to the physics world
		* 
		* \return Shared<PhysB::PhysicsWorld>
		*/
		Shared<PhysB::PhysicsWorld> getPhysics() { return m_Physics; };

		/**
		* get a link to the cache struct
		* 
		* \return Shared<Cache>
		*/
		Shared<Cache> getCache() { return m_cache; };
		/**
		* Get size of the window.
		* 
		* \param INT w Pointer to output variable for width.
		* \param INT h Pointer to output variable for height.
		*/
		void getWindowSize(int* w, int* h) { SDL_GetWindowSize(m_window, w, h); };

	private:
		void eventManager(); ///< Function that manages user input

		ALCdevice* device; ///< Audio device
		ALCcontext* context; ///< Audio context

		Shared<PhysB::PhysicsWorld> m_Physics; ///< Link to the physics world

		Shared<Input> m_input; ///< Pointer to the input manager struct.
		Shared<Cache> m_cache; ///< Pointer to the resource manager struct
		SDL_Window* m_window; ///< The window of the program
		SDL_GLContext m_context; ///< OpenGL context
		std::list<Shared<Entity>> m_entities; ///< List of every entity in the scene
		Shared<SceneTime> environment; ///< Pointer to the environment manager struct
		bool m_running = false; ///< Current state of the program
		Weak<Core> m_self; ///< Pointer to self
		bool PhysMultiThreading = false; /// Whether to use multithreading for physics calculations
	};
}