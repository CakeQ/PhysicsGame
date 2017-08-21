//! Object class.
/*!
	Object class that contains basic structure of any physics object within the game. supports rendering and collision
*/

#pragma once

#include <SFML\Graphics.hpp>
#include <Box2D\Box2D.h>

class object {
private:
	bool Collision = false;
	float XPos, YPos, Width, Height;

	b2BodyDef BodyDef;
	b2Body* Body;

	b2PolygonShape Shape;
	b2FixtureDef FixtureDef;

	sf::Texture Texture;
	sf::Sprite Sprite;

public:
	object(b2World iWorld, float iXPos, float iYPos, float iWidth, float iHeight, double SCALE);		//!< Object constructor
	~object();		//!< Object destructor

	void update();	//!< Update object position
	void draw(sf::RenderWindow window, double SCALE);	//!< Draw object on screen
};