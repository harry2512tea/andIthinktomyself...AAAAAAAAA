#include <iostream>
#include <memory>
#include <typeinfo>
#include <ThomasTheTank/ThomasTheTank.h>
#include <thread>
#include "Player.h"
#include "Asteroid.h"

using namespace ThomasTheTank;
#define Shared std::shared_ptr


int main()
{

	Shared<Core> core = Core::Initialise();

	Shared<Entity> e = core->addEntity();
	Shared<Entity> Cam = core->addEntity();
	Shared<Entity> e2 = core->addEntity();
	Shared<Entity> e3 = core->addEntity();
	Shared<Entity> e4 = core->addEntity();
	Shared<Entity> e5 = core->addEntity();
	Shared<Entity> e6 = core->addEntity();
	Shared<Entity> e7 = core->addEntity();

	e->getTransform()->setPosition(vec3(0.0f, 0.0f, -18.0f));
	e->getTransform()->setRotation(vec3(90.0f, 180.0f, 0.0f));

	e2->getTransform()->setPosition(vec3(5.0f, 15.0f, -18.0f));
	e3->getTransform()->setPosition(vec3(-2.0f, 18.0f, -18.0f));
	e4->getTransform()->setPosition(vec3(-8.0f, 32.0f, -18.0f));
	e5->getTransform()->setPosition(vec3(-13.0f, 49.0f, -18.0f));
	e6->getTransform()->setPosition(vec3(8.0f, 28.0f, -18.0f));
	e7->getTransform()->setPosition(vec3(12.0f, 44.0f, -18.0f));


	//Shared<Model> Ship = core->getCache()->load<Model>("../data/h2f2obj/f.obj");
	//Shared<Texture> ShipTexture = core->getCache()->load<Texture>("../data/h2f2obj/mat.png");


	e->addComponent<Player>();

	//Shared<MeshRenderer> curuthers = e->addComponent<MeshRenderer>();
	//curuthers->SetModel(Ship);
	//curuthers->SetTexture(ShipTexture);

	e2->addComponent<Asteroid>();
	e3->addComponent<Asteroid>();
	e4->addComponent<Asteroid>();
	e5->addComponent<Asteroid>();
	e6->addComponent<Asteroid>();
	e7->addComponent<Asteroid>();

	Shared<AudioClip> music = core->getCache()->load<AudioClip>("../data/Game-Music.ogg");
	Shared<Camera> cam = Cam->addComponent<Camera>();
	Shared<AudioSource> source = Cam->addComponent<AudioSource>();
	source->setClip(music);
	source->setLoop(true);
	source->setPitch(1.0f);
	source->setVolume(0.1f);
	source->Play();

	core->start();


  return 0;
}