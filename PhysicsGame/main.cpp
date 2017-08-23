/**
@File main.cpp
*/

/**
* \mainpage Physics Game
*/

#include <SFML\Graphics.hpp>
#include <Box2D\Box2D.h>
#include <game.h>

int main() /** Main Proc */
{
	const double SCALE = 30.0; //Box2D Pixel Scale
	bool KeyCoolDown = false;
	game GameController;

	//Window properties
	int iWinWidth = 1024;
	int iWinHeight = 800;

	sf::RenderWindow window(sf::VideoMode(iWinWidth, iWinHeight), "Physics Game");
	window.setFramerateLimit(60);

	//Box2D World setup
	b2Vec2 Gravity(0.0f, 10.0f);
	b2World World(Gravity);

	GameController.CreateGround(World, (iWinWidth/2), (iWinHeight-20), SCALE);	//Bottom Wall
	GameController.CreateGround(World, (iWinWidth / 2), (-90), SCALE);			//Top wall
	
	sf::Texture GroundTexture;
	sf::Texture BoxTexture;
	GroundTexture.loadFromFile("../img/ground.png");
	BoxTexture.loadFromFile("../img/box.png");

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

			//Key inputs
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Right)
				{
					if (KeyCoolDown == false)
					{
						int MouseX = sf::Mouse::getPosition(window).x;
						int MouseY = sf::Mouse::getPosition(window).y;
						GameController.CreateBox(World, MouseX, MouseY, SCALE);
					}
				}
			}

			if (event.type == sf::Event::MouseButtonReleased)
			{
				if (event.mouseButton.button == sf::Mouse::Right)
				{
					KeyCoolDown = false;
				}
			}

			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::C)
				{
					for (b2Body* BodyIterator = World.GetBodyList(); BodyIterator != 0; BodyIterator = BodyIterator->GetNext())
					{
						if (BodyIterator->GetType() == b2_dynamicBody)
						{
							//Delete all boxes
						}
					}
				}
			}
		}

		//Simulate the world
		World.Step(1 / 60.f, 8, 3);

		window.clear();

		int bodycount = World.GetBodyCount();
		Text.setString(std::to_string(bodycount));

		//Draw all objects in game. Very WIP as it only uses 2 obj types. REPLACE
		/*for (b2Body* BodyIterator = World.GetBodyList(); BodyIterator != 0; BodyIterator = BodyIterator->GetNext())
		{
			if (BodyIterator->GetType() == b2_staticBody)
			{
				sf::Sprite GroundSprite;
				GroundSprite.setTexture(GroundTexture);
				GroundSprite.setOrigin(iWinWidth / 2, 8.f);
				GroundSprite.setPosition(BodyIterator->GetPosition().x * SCALE, BodyIterator->GetPosition().y * SCALE);
				GroundSprite.setRotation(180 / b2_pi * BodyIterator->GetAngle());
				window.draw(GroundSprite);
			}
			else
			{
				sf::Sprite Sprite;

				Sprite.setTexture(BoxTexture);
				Sprite.setOrigin((16.0f / 2), (16.0f / 2));
				Sprite.setPosition(SCALE * BodyIterator->GetPosition().x, SCALE * BodyIterator->GetPosition().y);
				Sprite.setRotation(BodyIterator->GetAngle() * 180 / b2_pi);
				window.draw(Sprite);
			}
		}*/

		GameController.draw(window, SCALE);

		window.draw(Text);
		window.display();
	}

	for (b2Body* BodyIterator = World.GetBodyList(); BodyIterator != 0; BodyIterator = BodyIterator->GetNext())
	{
		World.DestroyBody(BodyIterator);
	}

	return 0;
}