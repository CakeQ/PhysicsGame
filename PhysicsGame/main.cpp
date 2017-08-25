/**
* \file main.cpp
*/

/*! \mainpage Pong Index Page Documentation
*
* \section intro_sec Introduction
*
* The project is a simple pong clone created in C++ using SFML and Box2D. The project was created entirely by Daniel Thompson for De Montfort University, Student number P15230940.
*
* \section running_sec Running The Game
*
* In order to run the game, launc PhysicsGame.exe located in the Debug folder.
*
* \section controls_sec Controls
*
* In order to start the game, press the space bar to spawn the pong ball. Once a player has scored, press space bar again to spawn another pong to continue. To exit the game, press the X button in the top right corner.
*
* \subsection player1 Player 1 Controls
*
* Player 1 is controlled as follows: Press the up arrow to move up, and the down arrow to move down.
*
* \subsection player2 Player 2 Controls
*
* Player 2 is controlled as follows: Press the W key to move up, and the S key to move down.
*
*/

#include <SFML\Graphics.hpp>
#include <Box2D\Box2D.h>
#include <game.h>
#include <object.h>
#include <vector>

int main()																										//!< Main loop that handles the entire program
{
	const double SCALE = 30.0; //Box2D Pixel Scale

	//Set window properties.
	int WinWidth = 1024;
	int WinHeight = 800;

	//Load background image.
	sf::Texture BackgroundTexture;
	if (!BackgroundTexture.loadFromFile("../img/background.png"))
		return -1;

	//Set background image.
	sf::Sprite Background;
	Background.setTexture(BackgroundTexture);

	sf::RenderWindow Window(sf::VideoMode(WinWidth, WinHeight), "Physics Game");
	Window.setFramerateLimit(60);

	//Box2D World setup.
	b2Vec2 Gravity(0.0f, 0.0f);
	b2World World(Gravity);

	//Initialise game controller.
	game GameController(World, WinWidth, WinHeight, SCALE);

	//Window loop.
	while (Window.isOpen())
	{
		sf::Event event;

		while (Window.pollEvent(event))
		{
			//Closing the window
			if (event.type == sf::Event::Closed)
			{
				Window.close();
			}

			GameController.handleInput(World, event);
		}

		//Simulate the world.
		World.Step(1 / 60.0f, 8, 3);

		//Update game controller.
		GameController.update(World);

		//Clear window.
		Window.clear(sf::Color::Black);

		//Draw background.
		Window.draw(Background);

		//Draw game.
		GameController.draw(Window);

		//Display window to screen.
		Window.display();

	}

	for (b2Body* BodyIterator = World.GetBodyList(); BodyIterator != 0; BodyIterator = BodyIterator->GetNext())
	{
		if (!BodyIterator)
			return 0;
		World.DestroyBody(BodyIterator);
	
	}

	return 0;
}