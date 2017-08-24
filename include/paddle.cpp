#include "paddle.h"
#include <iostream>

paddle::paddle(b2World& iWorld, float iXPos, float iYPos, float iWidth, float iHeight, double iSCALE, int iPlayer) : object(iWorld, iXPos, iYPos, iWidth, iHeight, iSCALE)
{
	Player = iPlayer;
	getBody()->SetFixedRotation(1);
}

paddle::~paddle()
{

}

void paddle::handleInput(sf::Event& iEvent)
{
	b2Vec2 Velocity;
	Velocity.x = 0;
	Velocity.y = 0;

	//Key inputs
	if (iEvent.type == sf::Event::KeyPressed)
	{
		if (Player == 1) 
		{
			if (iEvent.key.code == sf::Keyboard::Up)
			{
				Velocity.y = 10;
				std::cout << "Player 1 Move up" << std::endl;
			}
		
			if (iEvent.key.code == sf::Keyboard::Down)
			{
				Velocity.y = -10;
				std::cout << "Player 1 Move down" << std::endl;
			}
		}
		if (Player == 2)
		{
			if (iEvent.key.code == sf::Keyboard::W)
			{
				Velocity.y = 10;
				std::cout << "Player 2 Move up" << std::endl;
			}

			if (iEvent.key.code == sf::Keyboard::S)
			{
				Velocity.y = -10;
				std::cout << "Player 2 Move down" << std::endl;
			}
		}
		update(Velocity);
	}
}
