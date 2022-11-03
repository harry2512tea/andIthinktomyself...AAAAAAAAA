#ifndef THOMASTHETANK_TIME_H
#define THOMASTHETANK_TIME_H

#include <memory>

#define Shared std::shared_ptr
#define Weak std::weak_ptr

namespace ThomasTheTank
{

	/**
	* Environment manager class.
	*/
	class SceneTime
	{
	public:
		/**
		* Get the time between the current frame and the last frame.
		* 
		* \return deltaTime time between frames.
		*/
		static float DeltaTime() { return deltaTime; }; 

	private:
		friend class Core;
		void tick(); ///< Function called on program tick.
		void initialize(); ///< Function called on creation of the class.
		static float deltaTime; ///< stored value of the time between frames.
		float lastTime; ///< the last time the tick function was called.
		Weak<SceneTime> m_self; ///< pointer to self.
	};
}
#endif