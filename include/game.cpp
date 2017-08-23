#include <game.h>
#include <Box2D\Box2D.h>
#include <object.h>

game::game()
{

}

game::~game()
{

}

void game::draw(sf::RenderWindow& window, double SCALE) 
{
	for (object Object : ObjectList) {
		Object.draw(window, SCALE);
	}
}

void game::CreateGround(b2World& iWorld, float iX, float iY, double iSCALE) {
	//Define body
	b2BodyDef BodyDef;
	BodyDef.position = b2Vec2(iX / iSCALE, iY / iSCALE); //Scale is used because Box2D coordinates arent the same as pixel coordinates
	BodyDef.type = b2_staticBody;
	b2Body* Body = iWorld.CreateBody(&BodyDef);

	//Define shape
	b2PolygonShape Shape;
	Shape.SetAsBox((1024.f / 2) / iSCALE, (16.f / 2) / iSCALE); // Creates a box shape. Divide your desired width and height by 2.
	b2FixtureDef FixtureDef;
	FixtureDef.density = 0.f;  // Sets the density of the body
	FixtureDef.shape = &Shape; // Sets the shape
	Body->CreateFixture(&FixtureDef); // Apply the fixture definition

	object NewObject(iWorld, iX, iY, 1024.f, 32.f, iSCALE);
	NewObject.setDynamic(0);
	ObjectList.push_back(NewObject);
}

void game::CreateBox(b2World& iWorld, int iX, int iY, double iSCALE) {
	object NewObject(iWorld, iX, iY, 32.0f, 32.0f, iSCALE);
	NewObject.setDynamic(1);
	ObjectList.push_back( NewObject );
};