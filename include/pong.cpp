#include "pong.h"

pong::pong(b2World& iWorld, float iXPos, float iYPos, double iSCALE) : object(iWorld, iXPos, iYPos, 32.0f, 32.0f, 1, iSCALE)
{
	getBody()->SetFixedRotation(1);
	getBody()->SetLinearDamping(0);

	Velocity.x = 0;
	Velocity.y = 0;
}

void pong::handleInput(sf::Event& iEvent)
{
	//Key inputs
	if (iEvent.type == sf::Event::KeyPressed)
	{
		if (iEvent.key.code == sf::Keyboard::Space)
		{
			startMoving();
		}
	}
}

void pong::startMoving()
{
	if (!Moving) {
		if (((rand() % 2) + 1) == 1)
			Velocity.x = 8;
		else
			Velocity.x = -8;

		/*if (((rand() % 2) + 1) == 1)
			Velocity.y = 8;
		else
			Velocity.y = -8;*/

		move(Velocity);
	}
	Moving = 1;
}

void pong::update()
{

}

void pong::move(b2Vec2& iVelocity)
{
	getBody()->SetLinearVelocity(iVelocity);
}