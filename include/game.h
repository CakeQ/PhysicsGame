//! Game controller class.
/*!
	Main holder class that contains all items used in the game on runtime
*/

#pragma once

#include <Box2D\Box2D.h>
#include <object.h>
#include <list>

class game {
private:
	std::vector<object> ObjectList;
	//object Player1, Player2;

	double SCALE;
	int WinWidth, WinHeight;

public:
	game(int iWinWidth, int iWinHeight, double iSCALE); //!< Game controller constructor
	~game(); //!< Game controller destructor

	virtual void draw(sf::RenderWindow& iWindow);
	//virtual void update();
	//virtual void handleInput(b2World& iWorld, sf::Event& Event);

	//Test functions
	void CreateGround(b2World& iWorld, float X, float Y);
	void CreateBox(b2World& iWorld, int MouseX, int MouseY);
};