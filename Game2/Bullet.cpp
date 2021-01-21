#include "GraphicsManager.h"
#include "InputManager.h"
#include "Bullet.h"

//							Constructors
/*****************************************************************************/
#pragma region Constructors

Bullet::Bullet()
{
	velX = 0;
	velY = 0;
}

Bullet::Bullet(float x, float y, float width, float height, float rotation, LTexture* texture, SDL_Rect* rectangle, int direction)
{
	//Inherited from Object
	this->centeredX = x;
	this->centeredY = y;
	this->width = width;
	this->height = height;
	this->rotation = rotation;
	this->texture = texture;
	this->collider = rectangle;
	this->tag = "Bullet";
	colliderType = colliderTypes::rect;

	if (direction > 0){
		velY = BULLET_VEL;
	}
	else{
		velY = -BULLET_VEL;
	}
}
#pragma endregion

//							Main functions
/*****************************************************************************/
#pragma region Main functions

void Bullet::Update(float dt) {
	//Move the bullet in Y axis
	centeredY -= velY * dt;
	if (centeredY + height < 0 || centeredY + height > GraphicsManager::SCREEN_HEIGHT)
	{
		SceneManager::GetInstance().GetCurrentScene()->DeleteObject(this);
	}
}
#pragma endregion

//							Getters
/*****************************************************************************/
#pragma region Getters

float Bullet::GetVelY()
{
	return velY;
}
#pragma endregion

/*****************************************************************************/