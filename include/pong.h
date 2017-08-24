#pragma once
#include <object.h>

class pong : public object {
private:

public:
	pong(b2World& iWorld, float iXPos, float iYPos, double iSCALE);

	void startMoving();
};