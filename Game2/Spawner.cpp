#include "Enemy.h"
#include "GraphicsManager.h"
#include "InputManager.h"
#include "Spawner.h"

//							Constructors
/*****************************************************************************/
#pragma region Constructors

Spawner::Spawner()
{
	timer = 0;
	timeBetweenSpawns = 1;

	bulletHeight = 0;
	bulletWidth = 0;
	bulletTexture = NULL;
	bulletCollider = NULL;
}

Spawner::Spawner(float whidth, float height, float timeSpawn, LTexture* texture, SDL_Rect* rectangle) : Object()
{
	//Inherited from Object
	this->centeredX = 0;
	this->centeredY = 0;
	this->width = whidth;
	this->height = height;
	this->rotation = 0;
	this->texture = texture;
	this->collider = rectangle;
	this->tag = "Spawner";
	colliderType = colliderTypes::rect;

	timer = 0;
	timeBetweenSpawns = timeSpawn;

	bulletHeight = 0;
	bulletWidth = 0;
	bulletTexture = NULL;
	bulletCollider = NULL;
}
#pragma endregion

//							Main function
/*****************************************************************************/
#pragma region Main function

void Spawner::Update(float dt)
{
	timer += dt;
	if (timer >= timeBetweenSpawns)
	{
		//Calculate random enemy in random position
		float type = (float)rand() / RAND_MAX;
		float xAux = rand() % (GraphicsManager::SCREEN_WIDTH - (int)width);
		Enemy* enemy;

		//40% chance of being normal
		if (type < 0.4)
		{
			enemy = new Enemy(xAux, -height, width, height, rotation, texture, collider, enemyType::normal);
		}
		//40% chance of being zigzag
		else if (type < 0.8)
		{
			enemy = new Enemy(xAux, -height, width, height, rotation, texture, collider, enemyType::zigzag);
		}
		//20% chance of being shooting
		else
		{
			enemy = new Enemy(xAux, -height, width, height, rotation, texture, collider, enemyType::shooting);
		}
		enemy->SetBulletAttributes(bulletWidth, bulletHeight, bulletTexture, bulletCollider);
		SceneManager::GetInstance().GetCurrentScene()->AddObject(enemy);
		timer = 0;
	}

}
#pragma endregion

//							Setters
/*****************************************************************************/
#pragma region Setters

void Spawner::SetBulletAttributes(float width, float height, LTexture* texture, SDL_Rect* collider)
{
	this->bulletWidth = width;
	this->bulletHeight = height;
	this->bulletTexture = texture;
	this->bulletCollider = collider;
}
#pragma endregion

/*****************************************************************************/



