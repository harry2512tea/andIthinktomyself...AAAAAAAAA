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
	vect3 Input::mousePos = vect3(0, 0, 0);
	vect2 Input::mouseInp = vect2(0, 0);
	Shared<Input> Input::m_self = nullptr;

	Shared<Input> Input::Initialise()
	{
		Shared<Input> rtn = std::make_shared<Input>();
		Input::m_self = rtn;

		return rtn;
	}

	Shared<Input> Input::getInstance()
	{
		return Input::m_self;
	}

	bool Input::getKeyDown(SDL_Keycode code)
	{
		for (auto it = Input::keyDown.begin(); it != keyDown.end(); it++)
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
		for (auto it = keyUp.begin(); it != keyUp.end(); it++)
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
				return true;
			}
		}
		return false;
	}

	bool Input::getButton(int _button)
	{
		for (auto it = Input::buttons.begin(); it != Input::buttons.end(); it++)
		{
			if ((*it) == _button)
			{
				return true;
			}
		}
		return false;
	}

	bool Input::getButtonDown(int _button)
	{
		for (auto it = Input::buttonDown.begin(); it != Input::buttonDown.end(); it++)
		{
			if ((*it) == _button)
			{
				return true;
			}
		}
		return false;
	}

	bool Input::getButtonUp(int _button)
	{
		for (auto it = Input::buttonUp.begin(); it != Input::buttonUp.end(); it++)
		{
			if ((*it) == _button)
			{
				return true;
			}
		}
		return false;
	}
}