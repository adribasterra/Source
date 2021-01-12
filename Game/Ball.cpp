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
	this->tag = "Ball";
	colliderType = colliderTypes::circle;
	
	//Own
	velX = BALL_VEL;
	velY = BALL_VEL;
}

Ball::~Ball()
{
	Object::~Object();
}

//								Main func
/*****************************************************************************/

void Ball::Update(float dt)
{
	x += velX;
	y += velY;

	//If ball reaches screen width limits, point
	if (x+width>= GraphicsManager::GetInstance().SCREEN_WIDTH) {
		velX = -BALL_VEL;
		//Destroy that ball and create a new one
		//Score to left
	}
	else if (x <= 0) {
		velX = BALL_VEL;
		//Destroy that ball and create a new one
		//Score to left
	}
	if (y + height >= GraphicsManager::GetInstance().SCREEN_HEIGHT || y <= 0)
	{
		velY = -BALL_VEL;
	}
}

void Ball::OnCollisionEnter(Object* other)
{
	if (other->GetTag() == "Paddle")
	{
		printf("colision");
		velX = -velX;
	}
	//if (collisionFrom == ColFrom::C_LEFT)	velX = BALL_VEL;
	//if (collisionFrom == ColFrom::C_RIGHT)	velX = -BALL_VEL;
	//if (collisionFrom == ColFrom::C_TOP)	velY = BALL_VEL;
	//if (collisionFrom == ColFrom::C_BOTTOM) velY = -BALL_VEL;
	//if (other->tag == "tag")
	{
		//Do something
	}
}