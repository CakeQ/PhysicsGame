/**
* \file game.cpp
*/

#include <Box2D\Box2D.h>
#include <game.h>
#include <paddle.h>
#include <pong.h>
#include <object.h>

game::game(b2World& iWorld, int iWinWidth, int iWinHeight, double iSCALE) : 
	//Initialise Player and Pong containers.
	Player1(iWorld, (iWinWidth - 25), (iWinHeight / 2), iSCALE, 1),
	Player2(iWorld, 25, (iWinHeight / 2), iSCALE, 2),
	Pong(iWorld, (WinWidth/2), (WinHeight/2), iSCALE)
{
	//Set variables from input.
	WinWidth = iWinWidth;
	WinHeight = iWinHeight;
	SCALE = iSCALE;
	ScoreText1Pos = (WinWidth / 2) + 50;
	ScoreText2Pos = (WinWidth / 2) - 50;
	CenterTextPos = (WinWidth / 2);

	//Add players to object list.
	ObjectList.push_back(Player1);
	ObjectList.push_back(Player2);

	//Create top and bottom walls.
	createWall(iWorld, (WinWidth / 2), (WinHeight - 20));
	createWall(iWorld, (WinWidth / 2), 20);			

	//Game hasn't started.
	Started = 0;

	//Reset Player scores.
	Player1Score = 0;
	Player2Score = 0;

	//Load game font.
	if (!GameFont.loadFromFile("../bit5x3.ttf"))
	{
		// Error...
	}

	//Set-up game texts.
	ScoreText1.setFont(GameFont);
	ScoreText1.setCharacterSize(48);
	ScoreText1.setColor(sf::Color::Green);
	ScoreText1.setString(std::to_string(Player1Score));
	ScoreText1.setPosition(sf::Vector2f(ScoreText1Pos, 50));
	centerTextPos(ScoreText1, ScoreText1Pos);

	ScoreText2.setFont(GameFont);
	ScoreText2.setCharacterSize(48);
	ScoreText2.setColor(sf::Color::Green);
	ScoreText2.setString(std::to_string(Player2Score));
	ScoreText2.setPosition(sf::Vector2f(ScoreText2Pos, 50));
	centerTextPos(ScoreText2, ScoreText2Pos);

	CenterText.setFont(GameFont);
	CenterText.setCharacterSize(24);
	CenterText.setColor(sf::Color::Green);
	CenterText.setString(sf::String("Press Space to Start"));
	CenterText.setPosition(sf::Vector2f(CenterTextPos, ((WinHeight / 2) - 8)));

	Player1ControlText.setFont(GameFont);
	Player1ControlText.setCharacterSize(24);
	Player1ControlText.setColor(sf::Color::Green);
	Player1ControlText.setString(sf::String("Up: Up Arrow, Down: Down Arrow"));
	Player1ControlText.setPosition(sf::Vector2f(((WinWidth - 15) - (Player1ControlText.getLocalBounds().width)), (WinHeight -60)));

	Player2ControlText.setFont(GameFont);
	Player2ControlText.setCharacterSize(24);
	Player2ControlText.setColor(sf::Color::Green);
	Player2ControlText.setString(sf::String("Up: W, Down: S"));
	Player2ControlText.setPosition(sf::Vector2f(15, (WinHeight - 60)));

	centerTextPos(CenterText, CenterTextPos);
}

game::~game()
{
	//Remove everything from object list.
	for (object Object : ObjectList) {
		ObjectList.pop_back();
	}
}

void game::draw(sf::RenderWindow& iWindow)
{
	//Draw everything in object list.
	for (object Object : ObjectList) {
		Object.draw(iWindow);
	}

	iWindow.draw(CenterText);
	iWindow.draw(ScoreText1);
	iWindow.draw(ScoreText2);
	iWindow.draw(Player1ControlText);
	iWindow.draw(Player2ControlText);
}

void game::update(b2World& iWorld)
{
	//Check for pong existence.
	if (!Pong.getBody()) {
		Started = 0;
	}

	//Update players and pong.
	Player1.update();
	Player2.update();
	Pong.update();
	
	//Check for win condition.
	if ((checkVictory() != 0) && Started) {
		switch(checkVictory()) {
		case 1:
			Player1Score += 1;
			ScoreText1.setString(std::to_string(Player1Score));
			centerTextPos(ScoreText1, ScoreText1Pos);
			CenterText.setString(sf::String("Player 1 Scores! Press space to start again."));
			centerTextPos(CenterText, CenterTextPos);
			Started = 0;
			break;
		case 2:
			Player2Score += 1;
			ScoreText2.setString(std::to_string(Player2Score));
			centerTextPos(ScoreText2, ScoreText2Pos);
			CenterText.setString(sf::String("Player 2 Scores! Press space to start again."));
			centerTextPos(CenterText, CenterTextPos);
			Started = 0;
			break;
		case 0:
			break;
		}
	}
}

void game::handleInput(b2World& iWorld, sf::Event& iEvent)
{
	//Key inputs.
	if (iEvent.type == sf::Event::KeyPressed)
	{
		//Start game.
		if (iEvent.key.code == sf::Keyboard::Space)
		{
			if (!Started) {
				Pong = createPong(iWorld);
				Pong.startMoving();
				Started = 1;
				CenterText.setString(sf::String(""));
			}
		}
	}
	//Transfer paddle controls to paddle objects.
	Player1.handleInput(iEvent);
	Player2.handleInput(iEvent);

}

int game::checkVictory()
{
	//Check for pong being out of bounds.
	if (Pong.getPos().x > WinWidth)
		return 2;
	else if (Pong.getPos().x < 0)
		return 1;
	else return 0;
}

void game::centerTextPos(sf::Text& iText, float iActualPos)
{
	sf::FloatRect textBounds = iText.getLocalBounds();
	iText.setPosition(sf::Vector2f((iActualPos - (textBounds.width / 2)), iText.getPosition().y));
}

void game::createWall(b2World& iWorld, float iX, float iY) {
	object NewObject(iWorld, iX, iY, (WinWidth - 25), 16.0f, 1, SCALE);
	NewObject.setDynamic(0);
	ObjectList.push_back( NewObject );
}

void game::createBox(b2World& iWorld, int iX, int iY) {
	object NewObject(iWorld, iX, iY, 32.0f, 32.0f, 1, SCALE);
	ObjectList.push_back( NewObject );
};

pong game::createPong(b2World& iWorld) {
	pong NewPong(iWorld, (WinWidth/2), (WinHeight/2), SCALE);
	ObjectList.push_back(NewPong);
	return NewPong;
}