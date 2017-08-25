/**
* \file object.cpp
*/

#include <object.h>

object::object(b2World& iWorld, float iXPos, float iYPos, float iWidth, float iHeight, int iRestitution, double iSCALE)
{	
	Width = iWidth;
	Height = iHeight;

	SCALE = iSCALE;

	//Define body.
	BodyDef.position = b2Vec2(iXPos / SCALE, iYPos / SCALE);			
	BodyDef.type = b2_dynamicBody;
	Body = iWorld.CreateBody(&BodyDef);

	//Define shape.
	Shape.SetAsBox((Width / 2) / SCALE, (Height / 2) / SCALE);		
	FixtureDef.density = 1.0f;										
	FixtureDef.friction = 0.7f;
	FixtureDef.shape = &Shape;										
	FixtureDef.restitution = iRestitution;

	Body->CreateFixture(&FixtureDef);								

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

void object::move(b2Vec2& iVelocity)
{
	Body->SetLinearVelocity(iVelocity);
}

b2Vec2 object::getPos()
{
	b2Vec2 Result;
	Result.x = getBody()->GetPosition().x * SCALE;
	Result.y = getBody()->GetPosition().y * SCALE;
	return Result;
}

void object::draw(sf::RenderWindow& window)
{
	//Define drawable.
	Box.setOrigin(sf::Vector2f((Width / 2), (Height / 2)));
	Box.setSize(sf::Vector2f(Width, Height));
	Box.setPosition(sf::Vector2f(((Body->GetPosition().x * SCALE)), ((Body->GetPosition().y * SCALE))));
	Box.setOutlineColor(sf::Color(0, 255, 0));
	Box.setOutlineThickness(1.0f);
	Box.setFillColor(sf::Color::Black);
	float degreeValue = (Body->GetAngle() * (180 / b2_pi));
	Box.setRotation(degreeValue);

	//Draw drawable.
	window.draw(Box);
}
