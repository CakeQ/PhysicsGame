/**
@File game.h
*/

//! Game class.
/*!
Game class that holds all items within the pong game. Handles all events such as victory conditions, spawning pongs and spawning everything on run.
Created by Daniel Thompson, P15230940.
*/

#pragma once

#include <Box2D\Box2D.h>
#include <object.h>
#include <paddle.h>
#include <pong.h>

class game {
private:
	std::vector<object> ObjectList;												//!< Contains all objects spawned in the game.
	paddle				Player1,												//!< Holder for Player 1 paddle.
						Player2;												//!< Holder for Player 2 paddle.
	pong				Pong;													//!< Holder for current pong.
	bool				Started;												//!< Dictates if the round has started.
	double				SCALE;													//!< Scale used to convert Box2D coordinates into window coordinates.
	int					WinWidth,												//!< Stores window width.
						WinHeight,												//!< Stores window height.
						Player1Score,											//!< Stores Player 1's score.
						Player2Score;											//!< Stores Player 2's score.
	float				ScoreText1Pos,											//!< Text position for Player 1's score.
						ScoreText2Pos,											//!< Text position for Player 2's score.
						CenterTextPos;											//!< Text position for center text.
	sf::Font			GameFont;												//!< Contains font used by text in game.
	sf::Uint32			CharSet[5] = { 0x4E16, 0x754C, 0x60A8, 0x597D, 0x0 };	//!< Contains unicode characters.
	sf::Text			ScoreText1,												//!< Text for Player 1's score.
						ScoreText2,												//!< Text for Player 2's score.
						Player1ControlText,										//!< Text for Player 1's controls.
						Player2ControlText,										//!< Text for Player 2's controls.
						CenterText;												//!< Text central display text.


public:
	game(b2World& iWorld, int iWinWidth, int iWinHeight, double iSCALE);		//!< Game controller constructor.
	~game();																	//!< Game controller destructor.
	virtual void		draw(sf::RenderWindow& iWindow);						//!< Draws all objects in the game.
	virtual void		update(b2World& iWorld);								//!< Updates all objects in the game.
	virtual void		handleInput(b2World& iWorld, sf::Event& Event);			//!< Handles all input in the game.
	int					checkVictory();											//!< Checks for player victory.
	void				centerTextPos(sf::Text& iText, float iActualPos);		//!< Centers text.
	void				createWall(b2World& iWorld, float X, float Y);			//!< Creates horizontal walls.
	void				createBox(b2World& iWorld, int MouseX, int MouseY);		//!< Creates test boxes (Not used within game normally).
	pong				createPong(b2World& iWorld);							//!< Creates Pong ball.
};