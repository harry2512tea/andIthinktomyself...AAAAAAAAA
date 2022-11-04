#include "Input.h"
#include <iostream>

namespace ThomasTheTank
{

	std::list<SDL_Keycode> Input::keys = {};
	std::list<SDL_Keycode> Input::keyDown = {};
	std::list<SDL_Keycode> Input::keyUp = {};
	std::list<int> Input::buttons = {};
	std::list<int> Input::buttonDown = {};
	std::list<int> Input::buttonUp = {};
	vec3 Input::mousePos = vec3(0.0f);
	vec2 Input::mouseInp = vec2(0.0f);


	bool Input::getKeyDown(SDL_Keycode code)
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

	bool Input::getKeyUp(SDL_Keycode code)
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

	bool Input::getKey(SDL_Keycode code)
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
	bool Input::getButton(int _button)
	{
		return false;
	}
	bool Input::getButtonDown(int _button)
	{
		return false;
	}
	bool Input::getButtonUp(int _button)
	{
		return false;
	}
}