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

void Ball::Update(float dt)
{
	printf("Virtual override of Object update in Ball");
	this->x += velX * dt;
	this->y += velY * dt;

	//If ball reaches screen width limits, point
	if (x >= GraphicsManager::GetInstance().SCREEN_WIDTH) {
		velX = -BALL_VEL;
		//Destroy that ball and create a new one
		//Score to left
	}
	else if (x - *circleCollider < 0) {
		velX = BALL_VEL;
		//Destroy that ball and create a new one
		//Score to left
	}
}

void Ball::OnCollisionEnter(Object* other)
{
	//if (collisionFrom == ColFrom::C_LEFT)	velX = BALL_VEL;
	//if (collisionFrom == ColFrom::C_RIGHT)	velX = -BALL_VEL;
	//if (collisionFrom == ColFrom::C_TOP)	velY = BALL_VEL;
	//if (collisionFrom == ColFrom::C_BOTTOM) velY = -BALL_VEL;
	//if (other->tag == "tag")
	{
		//Do something
	}
}