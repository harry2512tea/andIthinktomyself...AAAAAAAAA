#include "Player.h"
#include <iostream>

void Player::onInitialize()
{
	getEntity()->addComponent<BoxCollider>();
	transform = getEntity()->getTransform();
	lives = 3;
	score = 0;
}

void Player::onTick()
{
	if (input->getKey(Keys::W))
	{
		transform->translate((((vec3(0.0f, 1.0f, 0.0f) * 2.0f /* * trans->getRotationQuat()*/) * SceneTime::DeltaTime())));
	}
	if (input->getKey(Keys::S))
	{
		transform->translate((((vec3(0.0f, -1.0f, 0.0f) * 2.0f /* * trans->getRotationQuat()*/) * SceneTime::DeltaTime())));
	}
	if (input->getKey(Keys::A))
	{
		transform->translate((((vec3(-1.0f, 0.0f, 0.0f) * 2.0f /* * trans->getRotationQuat()*/) * SceneTime::DeltaTime())));
	}
	if (input->getKey(Keys::D))
	{
		transform->translate((((vec3(1.0f, 0.0f, 0.0f) * 2.0f /* * trans->getRotationQuat()*/) * SceneTime::DeltaTime())));
	}

	score += SceneTime::DeltaTime() * 1000;
}

void Player::onCollisionEnter(Shared<PhysB::CollisionRet> collision)
{
	std::cout << "Collision Enter" << std::endl;
	/*if (lives > 0)
	{
		lives--;
		transform->setPosition(vec3(0.0f, 0.0f, 0.0f));
	}

	if (lives <= 0)
	{
		getCore()->stop();
	}*/
}