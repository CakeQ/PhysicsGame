//! Game controller class.
/*!
	Main holder class that contains all items used in the game on runtime
*/

#pragma once

#include <Box2D\Box2D.h>
#include <object.h>
#include <paddle.h>
#include <pong.h>

class game {
private:
	std::vector<object> ObjectList;
	paddle Player1, Player2;
	pong Pong;

	double SCALE;
	int WinWidth, WinHeight;

	bool started = 0;

public:
	game(b2World& iWorld, int iWinWidth, int iWinHeight, double iSCALE); //!< Game controller constructor
	~game(); //!< Game controller destructor

	virtual void draw(sf::RenderWindow& iWindow);
	virtual void update();
	virtual void handleInput(b2World& iWorld, sf::Event& Event);

	void CreateWall(b2World& iWorld, float X, float Y);
	void CreateBox(b2World& iWorld, int MouseX, int MouseY);
	pong CreatePong(b2World& iWorld);
};