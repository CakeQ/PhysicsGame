#include <object.h>

object::object(b2World& iWorld, float iXPos, float iYPos, float iWidth, float iHeight, double SCALE)
{
	Texture.loadFromFile("../img/box.png");

	//Define body
	BodyDef.position = b2Vec2(iXPos / SCALE, iYPos / SCALE);		//!< Scale is used because Box2D coordinates arent the same as pixel coordinates
	BodyDef.type = b2_staticBody;
	Body = iWorld.CreateBody(&BodyDef);

	//Define shape
	Shape.SetAsBox((iWidth / 2) / SCALE, (iHeight / 2) / SCALE);	//!< Creates a box shape. Divide your desired width and height by 2.
	FixtureDef.density = 0.f;										//!< Sets the density of the body
	FixtureDef.shape = &Shape;										//!< Sets the shape
	Body->CreateFixture(&FixtureDef);								//!< Apply the fixture definition
}

object::~object()
{

}

void object::setDynamic(bool Dynamic)
{
	if (Dynamic)
	{
		BodyDef.type = b2_dynamicBody;
	}
	else
	{
		BodyDef.type = b2_staticBody;
	}
}

void object::update()
{

}

void object::draw(sf::RenderWindow& window, double SCALE)
{
	sf::Sprite Sprite;

	Sprite.setTexture(Texture);
	Sprite.setOrigin((Width / 2), (Height / 2));
	Sprite.setPosition(SCALE * Body->GetPosition().x, SCALE * Body->GetPosition().y);
	Sprite.setRotation(Body->GetAngle() * 180 / b2_pi);
	window.draw(Sprite);
}
