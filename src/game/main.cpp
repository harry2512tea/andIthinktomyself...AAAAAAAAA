#include <iostream>
#include <memory>
#include <typeinfo>
#include <ThomasTheTank/ThomasTheTank.h>
#include <thread>

using namespace ThomasTheTank;
#define Shared std::shared_ptr


struct Player : Component
{
	Shared<Transform> trans;
	Shared<RigidBody> body;

	void onInitialize()
	{
		body = getEntity()->getComponent<RigidBody>();
		trans = getEntity()->getTransform();
		//trans->setPosition(vec3(0.0f, 0.0f, -5.0f));
	}

	void onTick()
	{
		trans = getEntity()->getTransform();
		if (input->getKey(Keys::W))
		{
			trans->translate((((vec3(0.0f, 0.0f, -1.0f) * 2.0f /* * trans->getRotationQuat()*/)*SceneTime::DeltaTime())));
		}
		if (input->getKey(Keys::S))
		{
			trans->translate((((vec3(0.0f, 0.0f, 1.0f) * 2.0f /* * trans->getRotationQuat()*/) * SceneTime::DeltaTime())));
		}
		if (input->getKey(Keys::A))
		{
			trans->translate((((vec3(-1.0f, 0.0f, 0.0f) * 2.0f /* * trans->getRotationQuat()*/) * SceneTime::DeltaTime())));
		}
		if (input->getKey(Keys::D))
		{
			trans->translate((((vec3(1.0f, 0.0f, 0.0f) * 2.0f /* * trans->getRotationQuat()*/) * SceneTime::DeltaTime())));
		}

		if (input->getKeyDown(Keys::F))
		{
			m_Entity.lock()->getComponent<RigidBody>()->AddForce(vec3(0.0f, -0.1f, 0.0f));
		}

		if (input->getKeyDown(Keys::SPACE))
		{
			body->setUseGravity(true);
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
		//trans->rotate(vec3(inp.y, inp.x, 0.0f) * 20.0f * SceneTime::DeltaTime());
	}

	void onDisplay()
	{
		
	}
};

struct Test : Component
{
	void onTick()
	{
		//Shared<Input> input = std::make_shared<Input>();
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
		

		rotationSpeed += 0.1f;
	}

	void onDisplay()
	{}

private:
	float rotationSpeed = 0.1f;
};

int main()
{

	Shared<Core> core = Core::Initialise();

	Shared<Entity> e = core->addEntity();
	Shared<Entity> e2 = core->addEntity();
	Shared<Entity> e3 = core->addEntity();

	e->getTransform()->setPosition(vec3(0.0f, 0.0f, -10.0f));
	e3->getTransform()->setPosition(vec3(0.0f, -5.0f, -10.0f));
	Shared<Model> Curuthers =  core->getCache()->load<Model>("../data/curuthers/curuthers.obj");
	Shared<Texture> CuruthersTexture = core->getCache()->load<Texture>("../data/curuthers/Whiskers_diffuse.jpg");

	Shared<RigidBody> e_body = e->addComponent<RigidBody>();
	e_body->setUseGravity(false);
	e->addComponent<Player>(); //std::cout << "_onTick" << std::endl;
	//e->addComponent<Test>();
	Shared<MeshRenderer> curuthers = e->addComponent<MeshRenderer>();
	curuthers->SetModel(Curuthers);
	curuthers->SetTexture(CuruthersTexture);

	Shared<MeshRenderer> curuthers2 = e3->addComponent<MeshRenderer>();
	curuthers2->SetModel(Curuthers);
	curuthers2->SetTexture(CuruthersTexture);
	
	
	//Shared<RigidBody> e_body2 = e->addComponent<RigidBody>();
	e->addComponent<BoxCollider>();
	e3->addComponent<BoxCollider>();

	
	//e_body->setUseGravity(true);

	//e->addComponent<AudioSource>();

	Shared<Camera> cam = e2->addComponent<Camera>();
	

	core->start();


  return 0;
}