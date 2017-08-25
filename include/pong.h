#pragma once
#include <object.h>

class pong : public object {
private:
	bool Moving = 0;
	int Direction = 1;
	b2Vec2 Velocity;
	float BaseSpeed = 12;

public:
	pong(b2World& iWorld, float iXPos, float iYPos, double iSCALE);

	void startMoving();
	void update();
	void move(b2Vec2 & iVelocity);
};