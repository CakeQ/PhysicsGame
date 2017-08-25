/**
@File object.h
*/

//! Object class.
/*!
	Object class that contains basic structure of any physics object within the game. supports rendering and collision.
	Created by Daniel Thompson, P15230940.
*/

#pragma once

#include <SFML\Graphics.hpp>
#include <Box2D\Box2D.h>

class object {
private:
	float				Width,																								//!< Object's width.
						Height;																								//!< Object's height.

	b2BodyDef			BodyDef;																							//!< Box2D Body Define.
	b2Body*				Body;																								//!< Box2D Body.

	b2PolygonShape		Shape;																								//!< Box2d Shape.
	b2FixtureDef		FixtureDef;																							//!< Box2d Fixture Define.

	sf::RectangleShape	Box;																								//!< SFML rendered box.

	double				SCALE;																								//!< Scale used to convert Box2D coordinates into window coordinates.
public:
	object(b2World& iWorld, float iXPos, float iYPos, float iWidth, float iHeight, int iRestitution, double iSCALE);		//!< Object constructor.
	b2Body*				getBody() { return Body; };																			//!< Returns Box2D of object.
	b2Vec2				getPos();																							//!< Returns world position.
	void				setDynamic(bool Dynamic);																			//!< Sets whether or not the Box2D body is dynamic.
	void				move(b2Vec2 & iVelocity);																			//!< Sets the object's velocity.
	void				draw(sf::RenderWindow& window);																		//!< Draws object on screen.
};