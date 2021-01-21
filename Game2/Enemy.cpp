#include "Enemy.h"
#include "GraphicsManager.h"
#include "InputManager.h"
#include "Bullet.h"

//							Constructors
/*****************************************************************************/
#pragma region Constructors

Enemy::Enemy()
{
	velX = 0;
	velY = 0;
	type = -1;

	timer = 0;
	timeBetweenShoots = 1;

	bulletHeight = 0;
	bulletWidth = 0;
	bulletTexture = NULL;
	bulletCollider = NULL;
}

Enemy::Enemy(float x, float y, float width, float height, float rotation, LTexture* texture, SDL_Rect* rectangle, int type)
{
	//Inherited from Object
	this->centeredX = x;
	this->centeredY = y;
	this->width = width;
	this->height = height;
	this->rotation = rotation;
	this->texture = texture;
	this->collider = rectangle;
	this->tag = "Enemy";
	colliderType = colliderTypes::rect;
	this->type = type;

	//Own
	if (this->type == enemyType::zigzag)
	{
		//Make random starting direction
		if ((float)rand() / RAND_MAX < 0.5) {
			velX = -ENEMY_VEL;
		}
		else {
			velX = ENEMY_VEL;
		}
	}
	timer = 0;
	timeBetweenShoots = 1;

	bulletHeight = 0;
	bulletWidth = 0;
	bulletTexture = NULL;
	bulletCollider = NULL;
}
#pragma endregion

//							Main functions
/*****************************************************************************/
#pragma region Main functions

void Enemy::Update(float dt)
{
	//Move enemy depending on type
	if (type == enemyType::normal)
	{
		centeredY += ENEMY_VEL * dt;
	}
	else if (type == enemyType::zigzag)
	{
		centeredY += ENEMY_VEL *dt;
		centeredX += velX * dt;
		if (centeredX + width > GraphicsManager::SCREEN_WIDTH || centeredX < 0)
		{
			velX  = -velX;
		}
	}
	else if (type == enemyType::shooting)
	{
		if (centeredY < 0)
		{
			centeredY += ENEMY_VEL * dt;
		}
		timer += dt;
		if (timer > timeBetweenShoots)
		{
			Shoot();
			timer = 0;
		}
	}

	if (centeredY > GraphicsManager::SCREEN_HEIGHT)
	{
		SceneManager::GetInstance().GetCurrentScene()->DeleteObject(this);
	}
}
#pragma endregion

//							Setters
/*****************************************************************************/
#pragma region Setters

void Enemy::SetBulletAttributes(float width, float height, LTexture* texture, SDL_Rect* collider)
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

void Enemy::OnCollisionEnter(Object* other)
{
	if (other->GetTag() == "Bullet" && ((Bullet*)other)->GetVelY() > 0)
	{
		SceneManager::GetInstance().GetCurrentScene()->DeleteObject(other);
		SceneManager::GetInstance().GetCurrentScene()->DeleteObject(this);
	}
}

void Enemy::Shoot()
{
	//Calculate centered position
	int centeredX = this->centeredX + this->width / 2 - bulletWidth / 2;
	int centeredY = this->centeredY + this->height;
	//Create bullet
	Bullet* bullet = new Bullet(centeredX, centeredY, bulletWidth, bulletHeight, rotation, bulletTexture, bulletCollider, 1);
	//Add it to the scene
	SceneManager::GetInstance().GetCurrentScene()->AddObject(bullet);
}
#pragma endregion

/*****************************************************************************/