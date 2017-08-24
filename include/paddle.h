#pragma once
#include <object.h>

class paddle : public object {
private:
	int Player;

public:
	paddle(b2World& iWorld, float iXPos, float iYPos, float iWidth, float iHeight, double iSCALE, int iPlayer);
	~paddle();

	void handleInput(sf::Event& iEvent);
};