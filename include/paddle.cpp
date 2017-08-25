/**
* \file paddle.cpp
*/

#include "paddle.h"

paddle::paddle(b2World& iWorld, float iXPos, float iYPos, double iSCALE, int iPlayer) : object(iWorld, iXPos, iYPos, 32.0f, 128.0f, 1, iSCALE)
{
	Player = iPlayer;
	StartPos = iXPos;

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

void paddle::update() {
	if (Moving != 0) 
	{
		b2Vec2 Velocity = getBody()->GetLinearVelocity();
		Velocity.y = 15 * Moving;
		move(Velocity);
	}

	int CurrentXPos = getBody()->GetPosition().x * 30;

	if (((CurrentXPos > (StartPos + 1))) || ((CurrentXPos < (StartPos - 1)))) {
		b2Vec2 ResetSpeed;
		ResetSpeed.x = (StartPos - CurrentXPos) * 10;
		ResetSpeed.y = 0;

		getBody()->ApplyForceToCenter(ResetSpeed,1);
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
