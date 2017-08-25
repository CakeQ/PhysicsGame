/**
@File main.cpp
*/

/**
* \mainpage Physics Game
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

	for (b2Body* BodyIterator = World.GetBodyList(); BodyIterator != 0; BodyIterator = BodyIterator->GetNext())	//!<
	{
		World.DestroyBody(BodyIterator);
	}

	return 0;
}