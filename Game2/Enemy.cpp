#include "Enemy.h"
#include "GraphicsManager.h"
#include "InputManager.h"
#include "Bullet.h"
//							Constructors
/*****************************************************************************/

Enemy::Enemy()
{
	this->velX = 0;
	this->velY = 0;
}

Enemy::Enemy(float x, float y, float width, float height, float rotation, LTexture* texture, SDL_Rect* rectangle, int type)
{
	//Inherited from Object
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->rotation = rotation;
	this->texture = texture;
	this->collider = rectangle;
	this->tag = "Enemy";
	colliderType = colliderTypes::rect;
	this->type = type;
	if (this->type == enemyType::zigzag)
	{
		if ((float)rand() / RAND_MAX < 0.5)
		{
			velX = -ENEMY_VEL;
		}
		else
		{
			velX = ENEMY_VEL;
		}
	}

}

Enemy::~Enemy()
{
	Object::~Object();
}

//								Main func
/*****************************************************************************/

void Enemy::Update(float dt) {
	//Move the paddle up or down
	if (type == enemyType::normal)
	{
		y += ENEMY_VEL * dt;
	}
	else if (type == enemyType::zigzag)
	{
		y += ENEMY_VEL *dt;
		x += velX * dt;
		if (x + width > GraphicsManager::SCREEN_WIDTH || x < 0)
		{
			velX *= -1;
		}
	}
	else if (type == enemyType::shooting)
	{
		if (y < 0)
		{
			y += ENEMY_VEL * dt;
		}
		timmer += dt;
		if (timmer > timeBetweenShoots)
		{
			Bullet* bullet = new Bullet(x + width / 2 - bulletWidth / 2, y+height, bulletWidth, bulletHeight, rotation, bulletTexture, bulletCollider, -1);
			SceneManager::GetInstance().GetCurrentScene()->AddObject(bullet);
			timmer = 0.0;
		}
	}

	if (y > GraphicsManager::SCREEN_HEIGHT)
	{
		SceneManager::GetInstance().GetCurrentScene()->DeleteObject(this);
	}

}

void Enemy::setBulletAttributes(float w, float h, LTexture* texture, SDL_Rect* col)
{
	bulletHeight = h;
	bulletWidth = w;
	bulletTexture = texture;
	bulletCollider = col;
}

void Enemy::OnCollisionEnter(Object* other)
{
	if (other->GetTag() == "Bullet" && ((Bullet*)other)->getVelY() > 0)
	{
		SceneManager::GetInstance().GetCurrentScene()->DeleteObject(other);
		SceneManager::GetInstance().GetCurrentScene()->DeleteObject(this);
	}
}





