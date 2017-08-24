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

int main() /** Main Proc */
{
	const double SCALE = 30.0; //Box2D Pixel Scale

	//Window properties
	int WinWidth = 1024;
	int WinHeight = 800;

	sf::Texture BackgroundTexture;

	if (!BackgroundTexture.loadFromFile("../img/background.png"))
		return -1;
	sf::Sprite Background;
	Background.setTexture(BackgroundTexture);

	sf::RenderWindow window(sf::VideoMode(WinWidth, WinHeight), "Physics Game");
	window.setFramerateLimit(60);

	//Box2D World setup
	b2Vec2 Gravity(0.0f, 0.0f);
	b2World World(Gravity);

	game GameController(World, WinWidth, WinHeight, SCALE);

	sf::Font   MyFont;
	sf::Uint32 MyCharset[] = { 0x4E16, 0x754C, 0x60A8, 0x597D, 0x0 }; // a set of unicode chinese characters
	if (!MyFont.loadFromFile("C:/Windows/Fonts/arial.ttf"))
	{
		// Error...
	}
	sf::Text Text;
	Text.setFont(MyFont);
	Text.setCharacterSize(24);

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			//Closing the window
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}

			GameController.handleInput(World, event);
		}

		//Simulate the world
		World.Step(1 / 60.0f, 8, 3);

		GameController.update();

		window.clear(sf::Color::Black);

		window.draw(Background);

		int bodycount = World.GetBodyCount();
		Text.setString(std::to_string(bodycount));


		GameController.draw(window);

		//window.draw(Text);

		window.display();
	}

	for (b2Body* BodyIterator = World.GetBodyList(); BodyIterator != 0; BodyIterator = BodyIterator->GetNext())
	{
		World.DestroyBody(BodyIterator);
	}

	return 0;
}