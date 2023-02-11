#include "Asteroid.h"
#include <random>
#include <time.h>

void Asteroid::onInitialize()
{
	transform = getEntity()->getTransform();
	originalPos = transform->getPosition();
	renderer = getEntity()->addComponent<MeshRenderer>();
	model = getCore()->getCache()->load<Model>("../data/RocksShortFlat_Obj/RockShortFlat_A.obj");
	texture = getCore()->getCache()->load<Texture>("../data/RocksShortFlat_Obj/ShortFlatRock_Rough1-Diffuse.png");
	

	renderer->SetModel(model);
	renderer->SetTexture(texture);
	renderer->setScale(vec3(0.3f));

	col = getEntity()->addComponent<BoxCollider>();
	col->setSize(vec3(2.0f, 1.0f, 2.0f));
	body = getEntity()->addComponent<RigidBody>();
	body->setUseGravity(false);
	std::srand(time(NULL));
	float force = rand() % 4 + 1;
	body->AddForce(vec3(0.0f, -2.0f, 0.0f) * force);
}

void Asteroid::onTick()
{
	if (transform->getPosition().y < -16)
	{
		std::srand(time(NULL));
		transform->setPosition(originalPos);
		body->setVelocity(vec3(0.0f));
		float force = rand() % 4 + (1 * difficulty);
		body->AddForce(vec3(0.0f, -1.0f, 0.0f) * force);
	}
	difficulty += 0.1f * SceneTime::DeltaTime();
}

void Asteroid::onCollisionEnter(Shared<PhysB::CollisionRet> collision)
{
	std::srand(time(NULL));
	transform->setPosition(originalPos);
	body->setVelocity(vec3(0.0f));
	float force = rand() % 4 + (1 * difficulty);
	body->AddForce(vec3(0.0f, -1.0f, 0.0f) * force);
}
