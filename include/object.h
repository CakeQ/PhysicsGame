//! Object class.
/*!
	Object class that contains basic structure of any physics object within the game. supports rendering and collision
*/

#pragma once

#include <SFML\Graphics.hpp>
#include <Box2D\Box2D.h>

class object {
private:
	float XPos, YPos, Width, Height;

	b2BodyDef BodyDef;
	b2Body* Body;

	b2PolygonShape Shape;
	b2FixtureDef FixtureDef;

	sf::Texture Texture;
	sf::Sprite Sprite;
	sf::RectangleShape Box;

	double SCALE;
public:
	object(b2World& iWorld, float iXPos, float iYPos, float iWidth, float iHeight, double iSCALE);		//!< Object 
	~object();		//!< Object destructor

	b2Body* getBody() { return Body; };

	void setDynamic(bool Dynamic);
	void update();
	void move(b2Vec2 & iVelocity);
	//!< Update object position
	void draw(sf::RenderWindow& window);	//!< Draw object on screen
};