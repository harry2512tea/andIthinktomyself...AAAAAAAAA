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
	renderer->setScale(vec3(0.7f));

	getEntity()->addComponent<BoxCollider>();
	body = getEntity()->addComponent<RigidBody>();
	body->setUseGravity(false);
	std::srand(time(NULL));
	float force = rand() % 4 + 1;
	body->AddForce(vec3(0.0f, -1.0f, 0.0f) * force);
}

void Asteroid::onTick()
{
}

void Asteroid::onCollisionEnter(Shared<PhysB::CollisionRet> collision)
{
	transform->setPosition(originalPos);
	body->setVelocity(vec3(0.0f));
}
