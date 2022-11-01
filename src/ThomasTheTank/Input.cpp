#include "Input.h"
#include <iostream>

namespace ThomasTheTank
{

	std::list<SDL_Keycode> Input::keys = {};
	std::list<SDL_Keycode> Input::keyDown = {};
	std::list<SDL_Keycode> Input::keyUp = {};

	bool ThomasTheTank::Input::getKeyDown(SDL_Keycode code)
	{
		for (auto it = Input::keys.begin(); it != keys.end(); it++)
		{
			if ((*it) == code)
			{
				//std::cout << "true" << std::endl;
				return true;
			}
		}
		//std::cout << "false" << std::endl;
		return false;
	}

	bool ThomasTheTank::Input::getKeyUp(SDL_Keycode code)
	{
		for (auto it = keys.begin(); it != keys.end(); it++)
		{
			if ((*it) == code)
			{
				//std::cout << "true" << std::endl;
				return true;
			}
		}
		//std::cout << "false" << std::endl;
		return false;
	}

	bool ThomasTheTank::Input::getKey(SDL_Keycode code)
	{
		for (auto it = Input::keys.begin(); it != Input::keys.end(); it++)
		{
			if ((*it) == code)
			{
				//std::cout << "true" << std::endl;
				return true;
			}
		}
		//std::cout << "false" << std::endl;
		return false;
	}
}