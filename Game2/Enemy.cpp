#include "Enemy.h"
#include "GraphicsManager.h"
#include "InputManager.h"
//							Constructors
/*****************************************************************************/

Enemy::Enemy()
{
	this->velX = 0;
	this->velY = 0;
}

Enemy::Enemy(float x, float y, float width, float height, float rotation, LTexture* texture, SDL_Rect* rectangle) : Object()
{
	//Inherited from Object
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->rotation = rotation;
	this->texture = texture;
	this->collider = rectangle;
	this->tag = "Bullet";
	colliderType = colliderTypes::rect;

}

Enemy::~Enemy()
{
	Object::~Object();
}

//								Main func
/*****************************************************************************/

void Enemy::Update(float dt) {
	//Move the paddle up or down
	y += ENEMY_VEL;
	if (y + texture->getHeight() > GraphicsManager::SCREEN_HEIGHT)
	{
		SceneManager::GetInstance().GetCurrentScene()->DeleteObject(this);
	}

}





