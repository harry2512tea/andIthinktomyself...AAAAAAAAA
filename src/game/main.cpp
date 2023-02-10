#include <iostream>
#include <memory>
#include <typeinfo>
#include <ThomasTheTank/ThomasTheTank.h>
#include <thread>
#include "Player.h"
#include "Asteroid.h"

using namespace ThomasTheTank;
#define Shared std::shared_ptr


//struct Player : Component
//{
//	Shared<Transform> trans;
//	Shared<RigidBody> body;
//
//	void onInitialize()
//	{
//		body = getEntity()->getComponent<RigidBody>();
//		trans = getEntity()->getTransform();
//		//trans->setPosition(vec3(0.0f, 0.0f, -5.0f));
//	}
//
//	void onTick()
//	{
//		trans = getEntity()->getTransform();
//		if (input->getKey(Keys::W))
//		{
//			trans->translate((((vec3(0.0f, 0.0f, -1.0f) * 2.0f /* * trans->getRotationQuat()*/)*SceneTime::DeltaTime())));
//		}
//		if (input->getKey(Keys::S))
//		{
//			trans->translate((((vec3(0.0f, 0.0f, 1.0f) * 2.0f /* * trans->getRotationQuat()*/) * SceneTime::DeltaTime())));
//		}
//		if (input->getKey(Keys::A))
//		{
//			trans->translate((((vec3(-1.0f, 0.0f, 0.0f) * 2.0f /* * trans->getRotationQuat()*/) * SceneTime::DeltaTime())));
//		}
//		if (input->getKey(Keys::D))
//		{
//			trans->translate((((vec3(1.0f, 0.0f, 0.0f) * 2.0f /* * trans->getRotationQuat()*/) * SceneTime::DeltaTime())));
//		}
//
//		if (input->getKeyDown(Keys::F))
//		{
//			m_Entity.lock()->getComponent<RigidBody>()->AddForce(vec3(0.0f, -0.1f, 0.0f));
//		}
//
//		if (input->getKeyDown(Keys::SPACE))
//		{
//			body->setUseGravity(true);
//		}
//
//		if (input->getKeyDown(Keys::ESCAPE))
//		{
//			std::cout << "locking/unlocking" << std::endl;
//			if (Cursor::lockState == Locked)
//			{
//				Cursor::lockState = None;
//			}
//			else
//			{
//				Cursor::lockState = Locked;
//			}
//		}
//		vec2 inp = input->mouseInput();
//		//trans->rotate(vec3(inp.y, inp.x, 0.0f) * 20.0f * SceneTime::DeltaTime());
//	}
//
//	void onCollisionEnter(Shared<PhysB::CollisionRet> collision)
//	{
//		std::cout << "Collision Enter" << std::endl;
//	}
//};


int main()
{

	Shared<Core> core = Core::Initialise();

	Shared<Entity> e = core->addEntity();
	Shared<Entity> e2 = core->addEntity();
	Shared<Entity> e3 = core->addEntity();

	e->getTransform()->setPosition(vec3(0.0f, 0.0f, -18.0f));
	e->getTransform()->setRotation(vec3(90.0f, 180.0f, 0.0f));
	e3->getTransform()->setPosition(vec3(0.0f, 16.0f, -18.0f));
	e3->getTransform()->setRotation(vec3(0.0f, 0.0f, 0.0f));


	Shared<Model> Ship = core->getCache()->load<Model>("../data/h2f2obj/f.obj");
	Shared<Texture> ShipTexture = core->getCache()->load<Texture>("../data/h2f2obj/mat.png");


	e->addComponent<Player>();

	Shared<MeshRenderer> curuthers = e->addComponent<MeshRenderer>();
	curuthers->SetModel(Ship);
	curuthers->SetTexture(ShipTexture);

	e3->addComponent<Asteroid>();


	Shared<Camera> cam = e2->addComponent<Camera>();
	

	core->start();


  return 0;
}