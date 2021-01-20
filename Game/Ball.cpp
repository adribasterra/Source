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
	ResetPosition();
}

Ball::~Ball()
{
	Object::~Object();
}

//								Main func
/*****************************************************************************/

void Ball::Update(float dt)
{
	x += velX * dt;
	y += velY * dt;

	//If ball reaches screen width limits, point
	if (x+width>= GraphicsManager::GetInstance().SCREEN_WIDTH) {
		ResetPosition();
		//Destroy that ball and create a new one
		//Score to left
	}
	else if (x <= 0) {
		ResetPosition();
		//Destroy that ball and create a new one
		//Score to left
	}
	if (y + height >= GraphicsManager::GetInstance().SCREEN_HEIGHT)
	{
		velY = -BALL_VEL;
	}
	if (y <= 0)
	{
		y = 0;
		velY = BALL_VEL;
	}
}

void Ball::OnCollisionEnter(Object* other)
{
	if (other->GetTag() == "Paddle")
	{
		velX *= -1;
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

void Ball::ResetPosition()
{
	x = GraphicsManager::GetInstance().SCREEN_WIDTH / 2 - width / 2;
	y = GraphicsManager::GetInstance().SCREEN_HEIGHT / 2 - height / 2;
	int randNum = rand() % 2; // Generate a random number between 0 and 1
	velX = (randNum>0) ? BALL_VEL : -BALL_VEL;
	randNum = rand() % 2;
	velY = (randNum > 0) ? BALL_VEL : -BALL_VEL;
}