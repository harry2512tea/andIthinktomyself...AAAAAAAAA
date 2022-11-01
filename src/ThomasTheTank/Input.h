#include <SDL2/SDL.h>
#include <list>
#include <memory>

#define Shared std::shared_ptr
#define Weak std::weak_ptr


namespace ThomasTheTank
{
	struct Input
	{
		bool getKeyDown(SDL_Keycode code);
		bool getKeyUp(SDL_Keycode code);
		bool getKey(SDL_Keycode code);
		//bool getMouseButtonDown();

	private:
		friend class Core;
		static std::list<SDL_Keycode> keys;
		static std::list<SDL_Keycode> keyDown;
		static std::list<SDL_Keycode> keyUp;
	};
}