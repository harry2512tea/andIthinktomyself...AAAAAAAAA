#include <iostream>
#include <memory>
#include <typeinfo>
#include <ThomasTheTank/ThomasTheTank.h>
//#define SDL_MAIN_HANDLED
//#include <SDL2/SDL.h>


using namespace ThomasTheTank;
#define Shared std::shared_ptr

struct Player : Component
{
	void onTick()
	{
		//std::cout << "ticking" << std::endl;
	}

	void onDisplay()
	{
		//std::cout << "display" << std::endl;
	}
};

struct Test : Component
{
	void onTick()
	{}

	void onDisplay()
	{}
};

int main()
{

	std::cout << "hello world" << std::endl;

	Shared<Core> core = Core::Initialise();

	Shared<Entity> e = core->addEntity();
	Shared<Entity> e2 = core->addEntity();

	e->addComponent<Player>();
	e->addComponent<Test>();
	e->addComponent<Player>();
	e->addComponent<TriangleRenderer>();
	//e->addComponent<Player>();

	Shared<Player> p = e->getComponent<Player>();
	std::cout << typeid(*p).name() << std::endl;

	Shared<Test> t = e->getComponent<Test>();
	std::cout << typeid(*t).name() << std::endl;

	core->start();


  return 0;
}