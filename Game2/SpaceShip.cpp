#include "SpaceShip.h"
#include "GraphicsManager.h"
#include "InputManager.h"
#include "Bullet.h"
//							Constructors
/*****************************************************************************/

SpaceShip::SpaceShip()
{
	this->velX = 0;
	this->velY = 0;
}

SpaceShip::SpaceShip(float x, float y, float width, float height, float rotation, LTexture* texture, SDL_Rect* rectangle) : Object()
{
	//Inherited from Object
	this->x = x;
	this->y = y;
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
}

SpaceShip::~SpaceShip()
{
	Object::~Object();
}

//								Main func
/*****************************************************************************/

void SpaceShip::Update(float dt) {
	velX = 0;
	velY = 0;
	timmer += dt;
	if (InputManager::GetInstance().GetKey(SDL_SCANCODE_S)) {
		velY += SPACESHIP_VEL;
	}
	if (InputManager::GetInstance().GetKey(SDL_SCANCODE_W)) {
		velY -= SPACESHIP_VEL;
	}
	if (InputManager::GetInstance().GetKey(SDL_SCANCODE_A)) {		// Commented as it does not need horizontal movement
		velX -= SPACESHIP_VEL;
	}
	if (InputManager::GetInstance().GetKey(SDL_SCANCODE_D)) {
		velX += SPACESHIP_VEL;
	}
	if (InputManager::GetInstance().GetKey(SDL_SCANCODE_SPACE) && timmer>timeBetweenShoots) {
		Shoot();
		timmer = 0.0;

	}
	//Move the paddle left or right
	x += velX;

	//If the paddle went too far to the left or right
	if ((x+width/2 < 0) || (x + width/2 > GraphicsManager::SCREEN_WIDTH))
	{
		//Move back
		x -= velX;
	}

	//Move the paddle up or down
	y += velY;
	//If the paddle went too far up or down
	if ((y < 0) || (y + height > GraphicsManager::SCREEN_HEIGHT))
	{
		//Move back
		y -= velY;
	}
}
void SpaceShip::setBulletAttributes(float w, float h, LTexture* texture, SDL_Rect* col)
{
	bulletHeight = h;
	bulletWidth = w;
	bulletTexture = texture;
	bulletCollider = col;
}

void SpaceShip::Shoot()
{
	Bullet* bullet = new Bullet(x+width/2-bulletWidth/2, y, bulletWidth, bulletHeight, rotation, bulletTexture, bulletCollider,1);
	SceneManager::GetInstance().GetCurrentScene()->AddObject(bullet);
}

void SpaceShip::HandleEvent(SDL_Event& e)
{
	//If a key was pressed
	if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
	{
		//Adjust the velocity
		switch (e.key.keysym.sym)
		{
		case SDLK_UP: velY -= SPACESHIP_VEL; break;
		case SDLK_DOWN: velY += SPACESHIP_VEL; break;
		case SDLK_LEFT: velX -= SPACESHIP_VEL; break;
		case SDLK_RIGHT: velX += SPACESHIP_VEL; break;
		}
	}
	//If a key was released
	else if (e.type == SDL_KEYUP && e.key.repeat == 0)
	{
		//Adjust the velocity
		switch (e.key.keysym.sym)
		{
		case SDLK_UP: velY += SPACESHIP_VEL; break;
		case SDLK_DOWN: velY -= SPACESHIP_VEL; break;
		case SDLK_LEFT: velX += SPACESHIP_VEL; break;
		case SDLK_RIGHT: velX -= SPACESHIP_VEL; break;
		}
	}
}




