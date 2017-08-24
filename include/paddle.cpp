#include "paddle.h"
#include <iostream>

paddle::paddle(b2World& iWorld, float iXPos, float iYPos, double iSCALE, int iPlayer) : object(iWorld, iXPos, iYPos, 32.0f, 128.0f, iSCALE)
{
	Player = iPlayer;

	if (Player == 1) {
		UpKey = sf::Keyboard::Up;
		DownKey = sf::Keyboard::Down;
	}
	else
	{
		UpKey = sf::Keyboard::W;
		DownKey = sf::Keyboard::S;
	}

	getBody()->SetFixedRotation(1);
	getBody()->SetLinearDamping(9);
}

paddle::~paddle()
{

}

void paddle::update() {
	if (Moving != 0) 
	{
		b2Vec2 Velocity = getBody()->GetLinearVelocity();
		Velocity.y = 15 * Moving;
		move(Velocity);
		std::cout << "moving Paddle" << std::endl;
	}
}

void paddle::handleInput(sf::Event& iEvent)
{
	//Key inputs
	if (iEvent.type == sf::Event::KeyPressed)
	{
		if (iEvent.key.code == UpKey)
		{
			Moving = -1;
		}

		else if (iEvent.key.code == DownKey)
		{
			Moving = 1;
		}
	}

	else if (iEvent.type == sf::Event::KeyReleased)
	{
		if (iEvent.key.code == UpKey) 
		{
			Moving = 0;
		}

		if (iEvent.key.code == DownKey)
		{
			Moving = 0;
		}
	}
}
