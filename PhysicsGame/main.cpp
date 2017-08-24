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
	std::vector<object> objectList;

	const double SCALE = 30.0; //Box2D Pixel Scale
	bool KeyCoolDown = false;

	//Window properties
	int WinWidth = 1024;
	int WinHeight = 800;

	sf::RenderWindow window(sf::VideoMode(WinWidth, WinHeight), "Physics Game");
	window.setFramerateLimit(60);

	//Box2D World setup
	b2Vec2 Gravity(0.0f, 0.0f);
	b2World World(Gravity);

	game GameController(WinWidth, WinHeight, SCALE);

	GameController.CreateGround(World, (WinWidth/2), (WinHeight-20));	//Bottom Wall
	GameController.CreateGround(World, (WinWidth / 2), 20);			//Top wall

	sf::Font   MyFont;
	sf::Uint32 MyCharset[] = { 0x4E16, 0x754C, 0x60A8, 0x597D, 0x0 }; // a set of unicode chinese characters
	if (!MyFont.loadFromFile("C:/Windows/Fonts/arial.ttf"))
	{
		// Error...
	}
	sf::Text Text;
	Text.setFont(MyFont);
	Text.setCharacterSize(24);

	object testObject(World, 500, 500, 32.0f, 32.0f, SCALE);

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

			//Key inputs
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Space)
				{
					GameController.CreateBox(World, 1024 / 2, 800 / 2);
				}
			}
			//GameController.handleInput(World, event);
		}

		//Simulate the world
		World.Step(1 / 60.0f, 8, 3);

		window.clear(sf::Color::Black);

		int bodycount = World.GetBodyCount();
		Text.setString(std::to_string(bodycount));


		GameController.draw(window);
		testObject.draw(window);

		//window.draw(Text);

		window.display();
	}

	/*for (b2Body* BodyIterator = World.GetBodyList(); BodyIterator != 0; BodyIterator = BodyIterator->GetNext())
	{
		World.DestroyBody(BodyIterator);
	}*/

	return 0;
}