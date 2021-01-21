#include "Ball.h"
#include "AudioManager.h"

//							Constructors
/*****************************************************************************/
#pragma region Constructors

Ball::Ball()
{
	velX = 0;
	velY = 0;
}

Ball::Ball(float x, float y, float width, float height, float rotation, LTexture* texture, float* radius, std::string audioPath)
{
	//Inherited from Object
	this->centeredX = x;
	this->centeredY = y;
	this->width = width;
	this->height = height;
	this->rotation = rotation;
	this->texture = texture;
	this->circleCollider = radius;
	this->tag = "Ball";
	colliderType = colliderTypes::circle;
	this->audioPath = audioPath;

	//Own
	velX = BALL_VEL;
	velY = BALL_VEL;

	ResetPosition();
}

#pragma endregion

//							Main functions
/*****************************************************************************/
#pragma region Main functions

void Ball::Update(float dt)
{
	centeredX += velX * dt;
	centeredY += velY * dt;

	//If ball reaches screen width limits, point
	if (centeredX + width>= GraphicsManager::GetInstance().SCREEN_WIDTH) {
		ResetPosition();
		GameManager::GetInstance().AddPointRight();
	}
	else if (centeredX <= 0) {
		ResetPosition();
		GameManager::GetInstance().AddPointLeft();
	}

	//If ball reaches screen height limits, bounce
	if (centeredY + height >= GraphicsManager::GetInstance().SCREEN_HEIGHT)
	{
		velY = -BALL_VEL;
	}
	if (centeredY <= 0)
	{
		centeredY = 0;
		velY = BALL_VEL;
	}
}
#pragma endregion

//							Others
/*****************************************************************************/
#pragma region Others

void Ball::OnCollisionEnter(Object* other)
{
	if (other->GetTag() == "Paddle")
	{
		velX  = -velX;
		AudioManager::GetInstance().PlayAudio(audioPath);
	}
}

void Ball::ResetPosition()
{
	centeredX = GraphicsManager::GetInstance().SCREEN_WIDTH / 2 - width / 2;
	centeredY = GraphicsManager::GetInstance().SCREEN_HEIGHT / 2 - height / 2;
	
	//Generate random direction - 50% chance / each
	int randNum = rand() % 2;
	velX = (randNum > 0) ? BALL_VEL : -BALL_VEL;

	randNum = rand() % 2;
	velY = (randNum > 0) ? BALL_VEL : -BALL_VEL;
}
#pragma endregion

/*****************************************************************************/