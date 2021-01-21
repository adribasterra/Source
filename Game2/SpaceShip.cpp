#include "SpaceShip.h"
#include "GraphicsManager.h"
#include "TimeManager.h"
#include "InputManager.h"
#include "Bullet.h"

//							Constructors
/*****************************************************************************/
#pragma region Constructors

SpaceShip::SpaceShip()
{
	velX = 0;
	velY = 0;
	
	timer = 0;
	timeBetweenShoots = 1;

	bulletHeight = 0;
	bulletWidth = 0;
	bulletTexture = NULL;
	bulletCollider = NULL;
}

SpaceShip::SpaceShip(float x, float y, float width, float height, float rotation, LTexture* texture, SDL_Rect* rectangle) : Object()
{
	//Inherited from Object
	this->centeredX = x;
	this->centeredY = y;
	this->width = width;
	this->height = height;
	this->rotation = rotation;
	this->texture = texture;
	this->collider = rectangle;
	this->tag = "SpaceShip";
	colliderType = colliderTypes::rect;

	//Own
	velX = 0;
	velY = 0;

	timer = 0;
	timeBetweenShoots = 1;

	bulletHeight = 0;
	bulletWidth = 0;
	bulletTexture = NULL;
	bulletCollider = NULL;
}
#pragma endregion

//							Setters
/*****************************************************************************/
#pragma region Setters

void SpaceShip::SetBulletAttributes(float width, float height, LTexture* texture, SDL_Rect* collider)
{
	this->bulletWidth = width;
	this->bulletHeight = height;
	this->bulletTexture = texture;
	this->bulletCollider = collider;
}
#pragma endregion

//							Others
/*****************************************************************************/
#pragma region Others

void SpaceShip::Shoot(int dir)
{
	//Calculate centered position
	int centeredX = this->centeredX + this->width / 2 - bulletWidth / 2;
	int centeredY = this->centeredY;
	//Create bullet
	Bullet* bullet = new Bullet(centeredX, centeredY, bulletWidth, bulletHeight, rotation, bulletTexture, bulletCollider, dir);
	//Add it to the scene
	SceneManager::GetInstance().GetCurrentScene()->AddObject(bullet);
}
#pragma endregion

/*****************************************************************************/