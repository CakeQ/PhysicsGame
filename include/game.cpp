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
	for (int i = 0; i < ObjectList.size(); i++) {
		ObjectList[i]->draw(window, SCALE);
	}
}

void game::CreateGround(b2World& World, float X, float Y, double SCALE) {
	//Define body
	b2BodyDef BodyDef;
	BodyDef.position = b2Vec2(X / SCALE, Y / SCALE); //Scale is used because Box2D coordinates arent the same as pixel coordinates
	BodyDef.type = b2_staticBody;
	b2Body* Body = World.CreateBody(&BodyDef);

	//Define shape
	b2PolygonShape Shape;
	Shape.SetAsBox((1024.f / 2) / SCALE, (16.f / 2) / SCALE); // Creates a box shape. Divide your desired width and height by 2.
	b2FixtureDef FixtureDef;
	FixtureDef.density = 0.f;  // Sets the density of the body
	FixtureDef.shape = &Shape; // Sets the shape
	Body->CreateFixture(&FixtureDef); // Apply the fixture definition
}

void game::CreateBox(b2World& World, int MouseX, int MouseY, double SCALE) {
	object* NewObject = new object(World, MouseX, MouseY, 32.0f, 32.0f, SCALE);
	ObjectList.push_back( NewObject );
};