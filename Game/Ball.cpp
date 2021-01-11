#include "Ball.h"

//							Constructors
/*****************************************************************************/

Ball::Ball(float x, float y, float width, float height, float rotation, LTexture* texture, float* radius)
{
	//Inherited from Object
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->rotation = rotation;
	this->texture = texture;
	this->circleCollider = radius;
	colliderType = colliderTypes::circle;
	
	//Own
	velX = 0;
	velY = 0;
}

Ball::~Ball()
{
	Object::~Object();
}

//								Main func
/*****************************************************************************/

void Ball::Update()
{
	printf("Virtual override of Object update in Ball");
}

void Ball::OnCollisionEnter(Object* other)
{
	//if (other->tag == "tag")
	{
		//Do something
	}
}