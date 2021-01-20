#include "Enemy.h"
#include "GraphicsManager.h"
#include "InputManager.h"
#include "Spawner.h"

//							Constructors
/*****************************************************************************/

Spawner::Spawner()
{
	timeUntileSpawn = 1.0;
}

Spawner::Spawner(float whidth, float height, float timeSpawn, LTexture* texture, SDL_Rect* rectangle) : Object()
{
	//Inherited from Object
	this->x = 0;
	this->y = 0;
	this->width = whidth;
	this->height = height;
	this->rotation = 0;
	this->texture = texture;
	this->collider = rectangle;
	this->tag = "Spawner";
	colliderType = colliderTypes::rect;
	timeUntileSpawn = timeSpawn;
}

Spawner::~Spawner()
{
	Object::~Object();
}

//								Main func
/*****************************************************************************/

void Spawner::Update(float dt) {
	//Move the paddle up or down
	timmer += dt;
	if (timmer >= timeUntileSpawn)
	{
		float type = (float)rand() / RAND_MAX;
		float xAux = rand() % (GraphicsManager::SCREEN_WIDTH- (int)width);
		Enemy* enemy;
		if (type<0.4)
		{
			enemy = new Enemy(xAux, -height, width, height, rotation, texture, collider, 0);
		}
		else if (type < 0.8)
		{
			enemy = new Enemy(xAux, -height, width, height, rotation, texture, collider, 1);
		}
		else
		{
			enemy = new Enemy(xAux, -height, width, height, rotation, texture, collider, 2);
			
		}
		enemy->setBulletAttributes(bulletWidth,bulletHeight,bulletTexture,bulletCollider);
		SceneManager::GetInstance().GetCurrentScene()->AddObject(enemy);
		timmer = 0.0;
	}

}

void Spawner::setBulletAttributes(float w, float h, LTexture* texture, SDL_Rect* col)
{
	bulletHeight = h;
	bulletWidth = w;
	bulletTexture = texture;
	bulletCollider = col;
}





