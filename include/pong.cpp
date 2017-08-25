#include "pong.h"

pong::pong(b2World& iWorld, float iXPos, float iYPos, double iSCALE) : object(iWorld, iXPos, iYPos, 32.0f, 32.0f, 1, iSCALE)
{
	getBody()->SetFixedRotation(1);
	getBody()->SetLinearDamping(0);

	Velocity.x = 0;
	Velocity.y = 0;
}

void pong::startMoving()
{
	if (!Moving) {
		if (((rand() % 2) + 1) == 1) {
			Velocity.x = BaseSpeed;
			Direction = 1;
		}
		else {
			Velocity.x = -BaseSpeed;
			Direction = -1;
		}

		if (((rand() % 2) + 1) == 1)
			Velocity.y = BaseSpeed;
		else
			Velocity.y = -BaseSpeed;

		move(Velocity);
	}
	Moving = 1;
}

void pong::update()
{
	b2Vec2 Speed = getBody()->GetLinearVelocity();
	if (Moving == 1) {
		if ((Speed.x < BaseSpeed) && (Speed.x > 0)) {
			Speed.x = BaseSpeed;
			Direction = 1;
		}
		if ((Speed.x > -BaseSpeed) && (Speed.x < 0)) {
			Speed.x = -BaseSpeed;
			Direction = -1;
		}
		if ((Speed.x) == 0)
			Speed.x = BaseSpeed * Direction;
		move(Speed);
	}
}

void pong::move(b2Vec2& iVelocity)
{
	getBody()->SetLinearVelocity(iVelocity);

}