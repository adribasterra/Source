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

Bullet::Bullet(float x, float y, float width, float height, float rotation, LTexture* texture, SDL_Rect* rectangle, int direction)
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
	if (direction > 0)
	{
		velY = BULLET_VEL;
	}
	else
	{
		velY = -BULLET_VEL;
	}
}

Bullet::~Bullet()
{
	Object::~Object();
}

//								Main func
/*****************************************************************************/

void Bullet::Update(float dt) {
	//Move the paddle up or down
	y -= velY;
	if (y+height < 0 || y + height > GraphicsManager::SCREEN_HEIGHT)
	{
		SceneManager::GetInstance().GetCurrentScene()->DeleteObject(this);
	}

}





