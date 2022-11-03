#include "Core.h"
#include "Entity.h"
#include "Components/Transform.h"
#include "TriangleRenderer.h"
#include "Time.h"
#include "Input.h"

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


		return rtn;
	}

	void Core::start()
	{
		m_running = true;

		environment = std::make_shared<SceneTime>();
		environment->initialize();
		input = std::make_shared<Input>();

		for (auto it = m_entities.begin(); it != m_entities.end(); it++)
		{
			std::cout << (*it)->name << std::endl;
			(*it)->initialize();
		}

		while (m_running)
		{
			input->keyDown.clear();
			input->keyUp.clear();

			SDL_Event event = { 0 };
			while (SDL_PollEvent(&event))
			{
				switch (event.type)
				{
				case SDL_QUIT:
					m_running = false;
					break;
				case SDL_KEYDOWN:
					if (!input->getKey(event.key.keysym.sym))
					{
						std::cout << "keydown" << std::endl;
						input->keyDown.push_back(event.key.keysym.sym);
						input->keys.push_back(event.key.keysym.sym);
					}
					break;
				case SDL_KEYUP:
					if (input->getKey(event.key.keysym.sym))
					{
						std::cout << "keyup" << std::endl;
						input->keys.remove(event.key.keysym.sym);
						input->keyUp.push_back(event.key.keysym.sym);
					}
					break;
				}
			}

			environment->tick();
			
			for (auto it = m_entities.begin(); it != m_entities.end(); it++)
			{
				(*it)->tick();
			}

			rend::Renderer r(1920, 1080);
			r.clear();

			for (auto it = m_entities.begin(); it != m_entities.end(); it++)
			{
				(*it)->display();
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

	
}
