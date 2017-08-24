#include <Box2D\Box2D.h>
#include <game.h>
#include <paddle.h>
#include <pong.h>
#include <object.h>

game::game(b2World& iWorld, int iWinWidth, int iWinHeight, double iSCALE) : 
	Player1(iWorld, (iWinWidth - 25), (iWinHeight / 2), iSCALE, 1),
	Player2(iWorld, 25, (iWinHeight / 2), iSCALE, 2),
	Pong(iWorld, (WinWidth/2), (WinHeight/2), iSCALE)
{
	WinWidth = iWinWidth;
	WinHeight = iWinHeight;
	SCALE = iSCALE;

	ObjectList.push_back(Player1);
	ObjectList.push_back(Player2);

	CreateWall(iWorld, (WinWidth / 2), (WinHeight - 20));	//Bottom Wall
	CreateWall(iWorld, (WinWidth / 2), 20);					//Top wall

	Pong = CreatePong(iWorld);
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
	Player1.update();
	Player2.update();
	Pong.update();
}

void game::handleInput(b2World& iWorld, sf::Event& iEvent)
{
	Pong.handleInput(iEvent);
	Player1.handleInput(iEvent);
	Player2.handleInput(iEvent);

}

void game::CreateWall(b2World& iWorld, float iX, float iY) {
	object NewObject(iWorld, iX, iY, (WinWidth - 25), 16.0f, 1, SCALE);
	NewObject.setDynamic(0);
	ObjectList.push_back( NewObject );
}

void game::CreateBox(b2World& iWorld, int iX, int iY) {
	object NewObject(iWorld, iX, iY, 32.0f, 32.0f, 1, SCALE);
	ObjectList.push_back( NewObject );
};

pong game::CreatePong(b2World& iWorld) {
	pong NewPong(iWorld, (WinWidth/2), (WinHeight/2), SCALE);
	ObjectList.push_back(NewPong);
	return NewPong;
}