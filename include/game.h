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
public:
	game(); //!< Game controller constructor
	~game(); //!< Game controller destructor

	void draw(sf::RenderWindow& window, double SCALE);

	//Test functions
	void CreateGround(b2World& World, float X, float Y, double SCALE);
	void CreateBox(b2World& World, int MouseX, int MouseY, double SCALE);
};