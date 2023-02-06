#include "Core.h"
#include "Entity.h"
#include "Components/Transform.h"
#include "TriangleRenderer.h"
#include "Time.h"
#include "Cursor.h"
#include "Components/Camera.h"
#include "Input.h"
#include "Cache.h"
#include "Exceptions.h"

#include <string>
#include <iostream>
#include <stdexcept>

#define INITIAL_WIDTH 1920
#define INITIAL_HEIGHT 1080

namespace ThomasTheTank
{


	Shared<Core> Core::Initialise()
	{
		Shared<Core> rtn = std::make_shared<Core>();
		rtn->m_self = rtn;

		rtn->m_window = SDL_CreateWindow("Thomas The Tank (game) Engine",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			1280, 720, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

		if (!(rtn->m_context = SDL_GL_CreateContext(rtn->m_window)))
		{
			SDL_DestroyWindow(rtn->m_window);
			SDL_Quit();
			throw std::runtime_error("Failed to create OpenGL context");
		}

		rtn->device = alcOpenDevice(NULL);

		if (!rtn->device)
		{
			throw std::runtime_error("Failed to open audio device");
		}

		rtn->context = alcCreateContext(rtn->device, NULL);

		if (!rtn->context)
		{
			alcCloseDevice(rtn->device);
			throw std::runtime_error("Failed to create audio context");
		}

		if (!alcMakeContextCurrent(rtn->context))
		{
			alcDestroyContext(rtn->context);
			alcCloseDevice(rtn->device);
			throw std::runtime_error("Failed to make context current");
		}

		//rtn->m_input = std::make_shared<Input>();
		//rtn->m_input->m_self = rtn->m_input;
		rtn->m_input = Input::Initialise();
		rtn->m_cache = Cache::Initialise();
		rtn->m_Physics = PhysB::PhysicsWorld::initialise(rtn->m_running, false);
		return rtn;
	}

	void Core::start()
	{
		m_running = true;

		environment = std::make_shared<SceneTime>();
		environment->initialize();
		//input = std::make_shared<Input>();

		/*for (auto it = m_entities.begin(); it != m_entities.end(); it++)
		{
			std::cout << (*it)->name << std::endl;
			(*it)->initialize();
		}*/

		if (PhysMultiThreading)
		{
			m_Physics->Start();
		}

		while (m_running)
		{

			eventManager();

			environment->tick();
			vec3 temp = Camera::main()->getEntity()->getTransform()->getPosition();
			//std::cout << temp.x << " " << temp.y << " " << temp.z << std::endl;
			alListener3f(AL_POSITION, temp.x, temp.y, temp.z); 

			for (auto it = m_entities.begin(); it != m_entities.end(); it++)
			{
				
				if ((*it)->enabled)
				{
					try
					{
						(*it)->tick();
					}
					catch (Exception& e)
					{
						std::cout << "Exception: " << e.what() << std::endl;
						(*it)->enabled = false;
					}
					catch (std::exception& e)
					{
						std::cout << "An unknown exception was thrown" << std::endl;
						(*it)->enabled = false;
					}
				}
				//(*it)->tick();
			}

			rend::Renderer r(1920, 1080);
			r.clear();

			for (auto it = m_entities.begin(); it != m_entities.end(); it++)
			{
				if ((*it)->enabled)
				{
					try
					{
						(*it)->lateTick();
					}
					catch (Exception& e)
					{
						std::cout << "Exception: " << e.what() << std::endl;
						(*it)->enabled = false;
					}
					catch (std::exception& e)
					{
						std::cout << "An unknown exception was thrown" << std::endl;
						(*it)->enabled = false;
					}
				}
				
			}

			for (auto it = m_entities.begin(); it != m_entities.end(); it++)
			{
				if ((*it)->enabled)
				{
					try
					{
						(*it)->display();
					}
					catch (Exception& e)
					{
						std::cout << "Exception: " << e.what() << std::endl;
						(*it)->enabled = false;
					}
					catch (std::exception& e)
					{
						std::cout << "An unknown exception was thrown" << std::endl;
						(*it)->enabled = false;
					}
				}
				
			}
			

			SDL_GL_SwapWindow(m_window);


			for (auto it = m_entities.begin(); it != m_entities.end(); it++)
			{
				if (!(*it)->alive())
				{
					(*it)->destroy();
					m_entities.erase(it);
					--it;
				}
			}
			if (!PhysMultiThreading)
			{
				m_Physics->Tick();
			}
		}
	}

	void Core::stop()
	{
		m_running = false;
	}

	Shared<Entity> Core::addEntity()
	{
		Shared<Entity> rtn = std::make_shared<Entity>();

		rtn->m_core = m_self;
		rtn->m_self = rtn;

		rtn->Transform = rtn->addComponent<Transform>();
		rtn->name = std::string("Entity ") + std::to_string(m_entities.size() + 1);
		

		m_entities.push_back(rtn);
		return rtn;
	}

	void Core::eventManager()
	{
		int x, y;
		getWindowSize(&x, &y);

		/*
		* LMB = 1
		* MMB = 3
		* RMB = 2
		* BACK = 4
		* FORWARD = 5
		*/
		m_input->keyDown.clear();
		m_input->keyUp.clear();
		m_input->buttonDown.clear();
		m_input->buttonUp.clear();

		//SDL_GetRelativeMouseState(& input->mouseInp.x, &input->mouseInp.y);
		//SDL_GetMouseState(&input->mousePos.x, &input->mousePos.y);

		m_input->mouseInp.x = 0;
		m_input->mouseInp.y = 0;

		//std::cout << input->mouseInp.x << " " << input->mouseInp.y << std::endl;

		SDL_Event event = { 0 };
		while (SDL_PollEvent(&event))
		{
			int button;
			switch (event.type)
			{
			case SDL_QUIT:
				m_running = false;
				break;

			case SDL_KEYDOWN:
				if (!m_input->getKey(event.key.keysym.sym))
				{
					//std::cout << "keydown" << std::endl;
					m_input->keyDown.push_back(event.key.keysym.sym);
					m_input->keys.push_back(event.key.keysym.sym);
				}
				break;

			case SDL_KEYUP:
				if (m_input->getKey(event.key.keysym.sym))
				{
					//std::cout << "keyup" << std::endl;
					m_input->keys.remove(event.key.keysym.sym);
					m_input->keyUp.push_back(event.key.keysym.sym);
				}
				break;

			case SDL_MOUSEBUTTONDOWN:
				button = (int)event.button.button;
				std::cout << event.button.button << std::endl;
				if (m_input->getButton(button))
				{
					std::cout << event.button.button << std::endl;
					m_input->buttons.push_back(button);
					m_input->buttonDown.push_back(button);
				}
				break;

			case SDL_MOUSEBUTTONUP:
				button = (int)event.button.button;
				if (m_input->getButton(button))
				{
					//std::cout << "mouseButtonUp" << std::endl;
					m_input->buttons.remove(button);
					m_input->buttonUp.push_back(button);
				}
				break;

			case SDL_MOUSEMOTION:
				
				m_input->mousePos.x = event.motion.x;
				m_input->mousePos.y = event.motion.y;
				
				m_input->mouseInp.x += event.motion.xrel;
				m_input->mouseInp.y += event.motion.yrel;
				break;
			}
		}

		if (Cursor::lockState == Locked)
		{
			SDL_WarpMouseInWindow(m_window, x / 2, y / 2);
			if (SDL_GetRelativeMouseMode)
			{
				SDL_SetRelativeMouseMode(SDL_FALSE);
			}
		}
		else if (Cursor::lockState == Confined)
		{
			if (!SDL_GetRelativeMouseMode)
			{
				SDL_SetRelativeMouseMode(SDL_TRUE);
			}
		}
		else if (Cursor::lockState == None)
		{
			if (SDL_GetRelativeMouseMode)
			{
				SDL_SetRelativeMouseMode(SDL_FALSE);
			}
		}
	}
}
