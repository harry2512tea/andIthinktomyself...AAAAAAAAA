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
		
	}

	void onDisplay()
	{
		
	}
};

struct Test : Component
{
	void onTick()
	{
		getEntity().lock()->getTransform()->rotate(vec3(0.0f, 0.5f, 0.0f));
	}

	void onDisplay()
	{}
};

int main()
{
	
	//std::cout << "hello world" << std::endl;

	Shared<Core> core = Core::Initialise();

	Shared<Entity> e = core->addEntity();
	Shared<Entity> e2 = core->addEntity();

	e->addComponent<Player>();
	e->addComponent<Test>();
	Shared<MeshRenderer> curuthers = e->addComponent<MeshRenderer>();
	curuthers->SetModel("../data/curuthers/curuthers.obj");
	curuthers->SetTexture("../data/curuthers/Whiskers_diffuse.jpg");
	e->getTransform()->setPosition(vec3(0.0f, 0.0f, -5.0f));

	Shared<Camera> cam = e2->addComponent<Camera>();
	core->setMainCam(cam);

	Shared<Player> p = e->getComponent<Player>();
	std::cout << typeid(*p).name() << std::endl;

	Shared<Test> t = e->getComponent<Test>();
	std::cout << typeid(*t).name() << std::endl;

	core->start();


  return 0;
}