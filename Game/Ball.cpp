#include "Ball.h"

//							Constructors
/*****************************************************************************/

Ball::Ball(float x, float y, float width, float height, float rotation, LTexture* texture, float* radius)
{
	//Object::Object(x, y, width, height, rotation, texture, radius);

	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->rotation = rotation;
	this->texture = texture;
	this->circleCollider = radius;
	colliderType = colliderTypes::circle;
}

Ball::~Ball()
{
	Object::~Object();
}

//								Main func
/*****************************************************************************/

void Ball::Update() {
	printf("Virtual override of Object update in Ball");
}