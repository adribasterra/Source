#include "GraphicsManager.h"
#include "InputManager.h"
#include "Bullet.h"
//							Constructors
/*****************************************************************************/

Bullet::Bullet()
{
	this->velX = 0;
	this->velY = 0;
}

Bullet::Bullet(float x, float y, float width, float height, float rotation, LTexture* texture, SDL_Rect* rectangle) : Object()
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

Bullet::~Bullet()
{
	Object::~Object();
}

//								Main func
/*****************************************************************************/

void Bullet::Update(float dt) {
	//Move the paddle up or down
	y -= BULLET_VEL;
	if (y + this->texture->getHeight() > GraphicsManager::SCREEN_HEIGHT)
	{
		//delete
	}

}





