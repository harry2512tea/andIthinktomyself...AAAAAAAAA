#include <iostream>
#include <memory>
#include <ThomasTheTank/ThomasTheTank.h>


using namespace ThomasTheTank;
#define Shared std::shared_ptr

struct Player : Component
{
	void onTick()
	{
		std::cout << "ticking" << std::endl;
	}

	void onDisplay()
	{
		std::cout << "display" << std::endl;
	}
};

int main()
{

	std::cout << "hello world" << std::endl;

	Shared<Core> core = Core::Initialise();

	Shared<Entity> e = core->addEntity();

	e->addComponent<Player>();
	e->addComponent<Player>();
	e->addComponent<Player>();

	core->start();


  return 0;
}