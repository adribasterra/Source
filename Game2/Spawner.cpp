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

Spawner::Spawner(float timeSpawn, LTexture* texture, SDL_Rect* rectangle) : Object()
{
	//Inherited from Object
	this->x = 0;
	this->y = 0;
	this->width = 0;
	this->height = 0;
	this->rotation = 0;
	this->texture = texture;
	this->collider = rectangle;
	this->tag = "Spawner";
	colliderType = colliderTypes::rect;

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
		if (type<0.4)
		{
			SceneManager::GetInstance().GetCurrentScene()->AddObject(new Enemy(x, -90,  84, 90, 0, texture, collider, 0));
		}
		else if (type < 0.8)
		{
			SceneManager::GetInstance().GetCurrentScene()->AddObject(new Enemy(x, -90, 84, 90, 0, texture, collider, 1));
		}
		else
		{
			SceneManager::GetInstance().GetCurrentScene()->AddObject(new Enemy(x, -90, 84, 90, 0, texture, collider, 2));
		}
	}

}





