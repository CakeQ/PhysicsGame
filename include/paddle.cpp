#include "paddle.h"

paddle::paddle(b2World& iWorld, float iXPos, float iYPos, float iWidth, float iHeight, double iSCALE, int iPlayer) : object(iWorld, iXPos, iYPos, iWidth, iHeight, iSCALE)
{
	Player = iPlayer;
}

paddle::~paddle()
{
}

void paddle::handleInput(sf::Event & iEvent)
{
	
}
