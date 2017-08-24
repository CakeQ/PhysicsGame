#pragma once
#include <object.h>

class pong : public object {
private:
	bool Moving = 0;
	b2Vec2 Velocity;

public:
	pong(b2World& iWorld, float iXPos, float iYPos, double iSCALE);

	void handleInput(sf::Event & iEvent);

	void startMoving();
	void update();
	void move(b2Vec2 & iVelocity);
};