#include <iostream>
#include <memory>
#include <typeinfo>
#include <ThomasTheTank/ThomasTheTank.h>
#include <thread>

using namespace ThomasTheTank;
#define Shared std::shared_ptr

struct Player : Component
{
	void onTick()
	{
		Shared<Input> input = std::make_shared<Input>();
		Shared<Transform> trans = getEntity()->getTransform();
		if (input->getKey(Keys::W))
		{
			trans->translate((((vec3(0.0f, 0.0f, -1.0f) * trans->getRotationQuat())*SceneTime::DeltaTime())));
		}
		if (input->getKey(Keys::S))
		{
			trans->translate((((vec3(0.0f, 0.0f, 1.0f) * trans->getRotationQuat()) * SceneTime::DeltaTime())));
		}
		if (input->getKey(Keys::A))
		{
			trans->translate((((vec3(-1.0f, 0.0f, 0.0f) * trans->getRotationQuat()) * SceneTime::DeltaTime())));
		}
		if (input->getKey(Keys::D))
		{
			trans->translate((((vec3(1.0f, 0.0f, 0.0f) * trans->getRotationQuat()) * SceneTime::DeltaTime())));
		}
		if (input->getKeyDown(Keys::ESCAPE))
		{
			std::cout << "locking/unlocking" << std::endl;
			if (Cursor::lockState == Locked)
			{
				Cursor::lockState = None;
			}
			else
			{
				Cursor::lockState = Locked;
			}
		}
		vec2 inp = input->mouseInput();
		trans->rotate(vec3(inp.y, inp.x, 0.0f) * 20.0f * SceneTime::DeltaTime());
	}

	void onDisplay()
	{
		
	}
};

struct Test : Component
{
	void onTick()
	{
		Shared<Input> input = std::make_shared<Input>();
		Shared<Transform> trans = getEntity()->getTransform();
		if (input->getKey(Keys::W))
		{
			trans->translate(vec3(0.0f, 0.0f, -1.0f * SceneTime::DeltaTime()));
			trans->setRotation(vec3(0.0f, 180.0f, 0.0f));
		}
		if (input->getKey(Keys::S))
		{
			trans->translate(vec3(0.0f, 0.0f, 1.0f * SceneTime::DeltaTime()));
			trans->setRotation(vec3(0.0f, 0.0f, 0.0f));
		}
		if (input->getKey(Keys::D))
		{
			trans->translate(vec3(1.0f * SceneTime::DeltaTime(), 0.0f, 0.0f));
			trans->setRotation(vec3(0.0f, 90.0f, 0.0f));
		}
		if (input->getKey(Keys::A))
		{
			trans->translate(vec3(-1.0f * SceneTime::DeltaTime(), 0.0f, 0.0f));
			trans->setRotation(vec3(0.0f, -90.0f, 0.0f));
		}
		if (input->getKey(Keys::F))
		{
			trans->rotate(vec3(0.0f, 1.0f, 0.0f));
		}
		if (input->getKey(Keys::G))
		{
			trans->rotate(vec3(0.0f, rotationSpeed, 0.0f));
			rotationSpeed += 0.5f;
		}
		
		//trans->setPosition(vec3();

		rotationSpeed += 0.1f;
	}

	void onDisplay()
	{}

private:
	float rotationSpeed = 0.1f;
};

int main()
{
	
	//std::cout << "hello world" << std::endl;

	Shared<Core> core = Core::Initialise();

	Shared<Entity> e = core->addEntity();
	Shared<Entity> e2 = core->addEntity();

	e2->addComponent<Player>();
	//e->addComponent<Test>();
	//e->addComponent<TriangleRenderer>();
	Shared<MeshRenderer> curuthers = e->addComponent<MeshRenderer>();
	curuthers->SetModel("../data/curuthers/curuthers.obj");
	curuthers->SetTexture("../data/curuthers/Whiskers_diffuse.jpg");
	e->getTransform()->setPosition(vec3(0.0f, 0.0f, -5.0f));

	Shared<Camera> cam = e2->addComponent<Camera>();
	//e2->getTransform()->setPosition(vec3(0.0f, 0.0f, 5.0f));

	Shared<Camera> cam2 = e->addComponent<Camera>();

	//Shared<Player> p = e->getComponent<Player>();
	//std::cout << typeid(*p).name() << std::endl;

	//Shared<Test> t = e->getComponent<Test>();
	//std::cout << typeid(*t).name() << std::endl;

	core->start();


  return 0;
}