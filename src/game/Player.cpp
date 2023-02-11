#include "Player.h"
#include <iostream>

void Player::onInitialize()
{
	col = getEntity()->addComponent<BoxCollider>();
	col->setSize(vec3(1.5f, 3.3f, 1.0f));
	transform = getEntity()->getTransform();

	renderer = getEntity()->addComponent<MeshRenderer>();
	model = getCore()->getCache()->load<Model>("../data/h2f2obj/f.obj");
	texture = getCore()->getCache()->load<Texture>("../data/h2f2obj/mat.png");

	explosionSource = getEntity()->addComponent<AudioSource>();
	engineSource = getEntity()->addComponent<AudioSource>();
	explosionClip = getCore()->getCache()->load<AudioClip>("../data/Game-explosion.ogg");
	engineClip = getCore()->getCache()->load<AudioClip>("../data/Engine_Audio.ogg");

	explosionSource->setClip(explosionClip);
	explosionSource->setPitch(1.0f);
	engineSource->setClip(engineClip);
	engineSource->setLoop(true);
	engineSource->setPitch(1.0f);

	renderer->SetModel(model);
	renderer->SetTexture(texture);
	renderer->setScale(vec3(0.5f));

	lives = 3;
	score = 0;

	engineSource->Play();
}

void Player::onTick()
{
	if (input->getKey(Keys::W))
	{
		transform->translate((((vec3(0.0f, 1.0f, 0.0f) * 8.0f /* * trans->getRotationQuat()*/) * SceneTime::DeltaTime())));
	}
	if (input->getKey(Keys::S))
	{
		transform->translate((((vec3(0.0f, -1.0f, 0.0f) * 8.0f /* * trans->getRotationQuat()*/) * SceneTime::DeltaTime())));
	}
	if (input->getKey(Keys::A))
	{
		transform->translate((((vec3(-1.0f, 0.0f, 0.0f) * 8.0f /* * trans->getRotationQuat()*/) * SceneTime::DeltaTime())));
	}
	if (input->getKey(Keys::D))
	{
		transform->translate((((vec3(1.0f, 0.0f, 0.0f) * 8.0f /* * trans->getRotationQuat()*/) * SceneTime::DeltaTime())));
	}

	if (transform->getPosition().x <= -22)
	{
		transform->setPosition(vec3(21.0f, transform->getPosition().y, transform->getPosition().z));
	}
	else if (transform->getPosition().x >= 22)
	{
		transform->setPosition(vec3(-21.0f, transform->getPosition().y, transform->getPosition().z));
	}

	if (transform->getPosition().y <= -12)
	{
		transform->setPosition(vec3(transform->getPosition().x, 11.0f, transform->getPosition().z));
	}
	else if (transform->getPosition().y >= 12)
	{
		transform->setPosition(vec3(transform->getPosition().x, -11.0f, transform->getPosition().z));
	}

	std::cout << transform->getPosition().y << std::endl;
	score += SceneTime::DeltaTime() * 1000;
}

void Player::onCollisionEnter(Shared<PhysB::CollisionRet> collision)
{
	//std::cout << "Collision Enter" << std::endl;
	/*if (lives > 0)
	{
		lives--;
		transform->setPosition(vec3(0.0f, 0.0f, 0.0f));
	}

	if (lives <= 0)
	{
		getCore()->stop();
	}*/

	explosionSource->Play();
}