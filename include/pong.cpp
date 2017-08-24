#include "pong.h"
#include <math.h>

pong::pong(b2World& iWorld, float iXPos, float iYPos, double iSCALE) : object(iWorld, iXPos, iYPos, 32.0f, 32.0f, iSCALE)
{
	getBody()->SetFixedRotation(1);
	getBody()->SetLinearDamping(0);
	startMoving();
}

void pong::startMoving()
{
	/*float Angle = (rand()%360)+1;
	if (Angle < 45)
		Angle = 45;
	else if ((Angle > 135) && (Angle <= 180))
		Angle = 135;
	else if ((Angle < 225) && (Angle > 180))
		Angle = 225;
	else if (Angle > 315)
		Angle = 315;
	Angle = Angle*(b2_pi / 180);
	*/
	b2Vec2 ForceToApply;
	ForceToApply.x = 10;

	b2Vec2 Force = b2Vec2((ForceToApply.x), (ForceToApply.y));

	getBody()->ApplyForceToCenter(Force, 1);
}
