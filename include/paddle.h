#pragma once
#include <object.h>

class paddle : public object {
private:
	int Player, Moving = 0, UpKey, DownKey;

public:
	paddle(b2World& iWorld, float iXPos, float iYPos, double iSCALE, int iPlayer);
	~paddle();

	void update();
	void handleInput(sf::Event& iEvent);
};