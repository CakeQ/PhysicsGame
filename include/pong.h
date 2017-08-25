/**
* \file pong.h
*/

//! Pong class.
/*!
Child class of Object class for the pong ball used in Pong.
Created by Daniel Thompson, P15230940.
*/

#pragma once

#include <object.h>

class pong : public object {
private:
	bool	Moving = 0;												//!< Dictates if the pong has started moving.
	int		Direction = 1;											//!< Contains pong's current x direction.
	b2Vec2	Velocity;												//!< Contains velocity of the pong.
	float	BaseSpeed = 10;											//!< Contains base speed of the pong.

public:
	pong(b2World& iWorld, float iXPos, float iYPos, double iSCALE);	//!< Pong constructor.
	void	startMoving();											//!< Stars pong movement.
	void	update();												//!< Updates pong movement and increases velocity if below a threshold. Ensures pong does not stop moving horizontally.
	void	move(b2Vec2 & iVelocity);								//!< Moves pong by velocity.
};