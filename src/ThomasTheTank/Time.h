#ifndef THOMASTHETANK_TIME_H
#define THOMASTHETANK_TIME_H

#include <memory>

#define Shared std::shared_ptr
#define Weak std::weak_ptr

namespace ThomasTheTank
{

	/**
	* Environment manager struct.
	*/
	struct SceneTime
	{
	public:
		/**
		* Get the time between the current frame and the last frame.
		* 
		* \return FLOAT deltaTime time between frames.
		*/
		static float DeltaTime() { return deltaTime; }; 

	private:
		friend struct Core;
		void tick(); ///< Function called on program tick.
		void initialize(); ///< Function called on creation of the struct.
		static float deltaTime; ///< stored value of the time between frames.
		float lastTime; ///< the last time the tick function was called.
		Weak<SceneTime> m_self; ///< pointer to self.
	};
}
#endif