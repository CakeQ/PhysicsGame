#include <object.h>

object::object(b2World& iWorld, float iXPos, float iYPos, float iWidth, float iHeight, double iSCALE)
{
	XPos = iXPos;
	YPos = iYPos;
	
	Width = iWidth;
	Height = iHeight;

	SCALE = iSCALE;

	//Define body
	BodyDef.position = b2Vec2(XPos / SCALE, YPos / SCALE);			//!< Scale is used because Box2D coordinates arent the same as pixel coordinates
	BodyDef.type = b2_dynamicBody;
	Body = iWorld.CreateBody(&BodyDef);

	//Define shape
	Shape.SetAsBox((Width / 2) / SCALE, (Height / 2) / SCALE);		//!< Creates a box shape. Divide your desired width and height by 2.
	FixtureDef.density = 1.0f;										//!< Sets the density of the body
	FixtureDef.friction = 0.7f;
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
		Body->SetType(b2_dynamicBody);
	}
	else
	{
		Body->SetType(b2_staticBody);
	}
}

void object::update()
{

}

void object::move(b2Vec2& iVelocity)
{
	Body->SetLinearVelocity(iVelocity);
}

void object::draw(sf::RenderWindow& window)
{
	//Define drawable
	Box.setOrigin(sf::Vector2f((Width / 2), (Height / 2)));
	Box.setSize(sf::Vector2f(Width, Height));
	Box.setPosition(sf::Vector2f(((Body->GetPosition().x * SCALE)), ((Body->GetPosition().y * SCALE))));
	Box.setOutlineColor(sf::Color(0, 255, 0));
	Box.setOutlineThickness(1.0f);
	Box.setFillColor(sf::Color::Black);
	float degreeValue = (Body->GetAngle() * (180 / b2_pi));
	Box.setRotation(degreeValue);

	window.draw(Box);
}
