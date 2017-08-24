#include <Box2D\Box2D.h>
#include <game.h>
#include <paddle.h>
#include <object.h>

game::game(b2World& iWorld, int iWinWidth, int iWinHeight, double iSCALE) : 
	Player1(iWorld, (iWinWidth - 25), (iWinHeight / 2), 32.0f, 128.0f, iSCALE, 1),
	Player2(iWorld, 25, (iWinHeight / 2), 32.0f, 128.0f, iSCALE, 2)
{
	WinWidth = iWinWidth;
	WinHeight = iWinHeight;
	SCALE = iSCALE;

	ObjectList.push_back(Player1);
	ObjectList.push_back(Player2);

	CreateGround(iWorld, (WinWidth / 2), (WinHeight - 20));	//Bottom Wall
	CreateGround(iWorld, (WinWidth / 2), 20);				//Top wall
}

game::~game()
{
	for (object Object : ObjectList) {
		ObjectList.pop_back();
	}
}

void game::draw(sf::RenderWindow& iWindow)
{
	for (object Object : ObjectList) {
		Object.draw(iWindow);
	}
}

void game::update()
{

}

void game::handleInput(b2World& iWorld, sf::Event& iEvent)
{
	//Key inputs
	if (iEvent.type == sf::Event::KeyPressed)
	{
		if (iEvent.key.code == sf::Keyboard::Space)
		{
				CreateBox(iWorld, 1024/2, 800/2);
		}
	}

	Player1.handleInput(iEvent);
	Player2.handleInput(iEvent);
}

void game::CreateGround(b2World& iWorld, float iX, float iY) {
	object NewObject(iWorld, iX, iY, (WinWidth - 50), 16.0f, SCALE);
	NewObject.setDynamic(0);
	ObjectList.push_back( NewObject );
}

void game::CreateBox(b2World& iWorld, int iX, int iY) {
	object NewObject(iWorld, iX, iY, 32.0f, 32.0f, SCALE);
	NewObject.setDynamic(1);
	ObjectList.push_back( NewObject );
};