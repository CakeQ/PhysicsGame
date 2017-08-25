/**
@File paddle.h
*/

//! Paddle class.
/*!
Child class of Object class for paddles used in Pong.
Created by Daniel Thompson, P15230940.
*/

#pragma once

#include <object.h>

class paddle : public object {
private:
	int		Player,																		//!< Dictates what controls are used.
			Moving = 0,																	//!< Dictates whether or not the paddle is allowed to move.
			UpKey,																		//!< Dictates what the up key is.
			DownKey;																	//!< Dictates what the down key is.
	float	StartPos;																	//!< Information stored on what the starting X position is for re-centering.

public:
	paddle(b2World& iWorld, float iXPos, float iYPos, double iSCALE, int iPlayer);		//!< Paddle constructor.
	void	update();																	//!< Update function that maintains pong speed.
	void	handleInput(sf::Event& iEvent);												//!< Handles paddle movement and re-centering
};