#include <Box2D\Box2D.h>
#include <game.h>
#include <paddle.h>
#include <object.h>

game::game(int iWinWidth, int iWinHeight, double iSCALE)
	//Player1(iWorld, (iWinWidth - 5), (iWinHeight / 2), 32.0f, 128.0f, iSCALE),
	//Player2(iWorld, 5, (iWinHeight / 2), 32.0f, 128.0f, iSCALE)
{
	WinWidth = iWinWidth;
	WinHeight = iWinHeight;
	SCALE = iSCALE;
}

game::~game()
{

}

void game::draw(sf::RenderWindow& iWindow)
{
	for (object Object : ObjectList) {
		Object.draw(iWindow);
	}
}

/*void game::handleInput(b2World& iWorld, sf::Event & iEvent)
{
	//Key inputs
	if (iEvent.type == sf::Event::KeyPressed)
	{
		if (iEvent.key.code == sf::Keyboard::Space)
		{
				CreateBox(iWorld, 1024/2, 800/2);
		}
	}

	b2Vec2 Velocity;
	Velocity.x = 0;
	Velocity.y = 0;

	//Key inputs
	if (iEvent.type == sf::Event::KeyPressed)
	{
		if (iEvent.key.code == sf::Keyboard::Up)
		{
			Velocity.y = 5;
			//Player1.update(Velocity);
		}

		if (iEvent.key.code == sf::Keyboard::Down)
		{
			Velocity.y = -5;
		}

		if (iEvent.key.code == sf::Keyboard::W)
		{
			Velocity.y = 5;
		}

		if (iEvent.key.code == sf::Keyboard::S)
		{
			Velocity.y = -5;
		}
	}
}*/

void game::CreateGround(b2World& iWorld, float iX, float iY) {
	object NewObject(iWorld, iX, iY, 1024.0f, 16.0f, SCALE);
	NewObject.setDynamic(0);
	ObjectList.push_back( NewObject );
}

void game::CreateBox(b2World& iWorld, int iX, int iY) {
	object NewObject(iWorld, iX, iY, 32.0f, 32.0f, SCALE);
	NewObject.setDynamic(1);
	ObjectList.push_back( NewObject );
};