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
	lives = 3;
	
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
	lives = 3;

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

void SpaceShip::Update(float dt)
{
	velX = 0;
	velY = 0;
	timer += dt;

	//Handle key inputs
	if (InputManager::GetInstance().GetKey(SDL_SCANCODE_S)) {
		velY += SPACESHIP_VEL;
	}
	if (InputManager::GetInstance().GetKey(SDL_SCANCODE_W)) {
		velY -= SPACESHIP_VEL;
	}
	if (InputManager::GetInstance().GetKey(SDL_SCANCODE_A)) {
		velX -= SPACESHIP_VEL;
	}
	if (InputManager::GetInstance().GetKey(SDL_SCANCODE_D)) {
		velX += SPACESHIP_VEL;
	}

	//Shoot
	if (InputManager::GetInstance().GetKey(SDL_SCANCODE_SPACE) && timer > timeBetweenShoots) {
		Shoot();
		timer = 0;
	}

	//Update movement in X axis
	centeredX += velX * dt;

	//Check screen borders
	if (centeredX + width/2 < 0)
	{
		//Move back
		centeredX += SPACESHIP_VEL * dt;
	}
	else if(centeredX + width / 2 > GraphicsManager::SCREEN_WIDTH)
	{
		centeredX -= SPACESHIP_VEL * dt;
	}

	//Update movement in Y axis
	centeredY += velY * dt;

	//Check screen borders
	if (centeredY < 0)
	{
		//Move back
		centeredY += SPACESHIP_VEL * dt;
	}
	else if (centeredY + height > GraphicsManager::SCREEN_HEIGHT)
	{
		centeredY -= SPACESHIP_VEL * dt;
	}
}

void SpaceShip::HandleEvent(SDL_Event& e)
{
	//On key pressed
	if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
	{
		//Adjust velocity
		switch (e.key.keysym.sym)
		{
			case SDLK_UP:		velY -= SPACESHIP_VEL; break;
			case SDLK_DOWN:		velY += SPACESHIP_VEL; break;
			case SDLK_LEFT:		velX -= SPACESHIP_VEL; break;
			case SDLK_RIGHT:	velX += SPACESHIP_VEL; break;
		}
	}
	//On key released
	else if (e.type == SDL_KEYUP && e.key.repeat == 0)
	{
		//Adjust velocity
		switch (e.key.keysym.sym)
		{
			case SDLK_UP:		velY += SPACESHIP_VEL; break;
			case SDLK_DOWN:		velY -= SPACESHIP_VEL; break;
			case SDLK_LEFT:		velX += SPACESHIP_VEL; break;
			case SDLK_RIGHT:	velX -= SPACESHIP_VEL; break;
		}
	}
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

void SpaceShip::Shoot()
{
	//Calculate centered position
	int centeredX = this->centeredX + this->width / 2 - bulletWidth / 2;
	int centeredY = this->centeredY;
	//Create bullet
	Bullet* bullet = new Bullet(centeredX, centeredY, bulletWidth, bulletHeight, rotation, bulletTexture, bulletCollider, 1);
	//Add it to the scene
	SceneManager::GetInstance().GetCurrentScene()->AddObject(bullet);
}

void SpaceShip::OnCollisionEnter(Object* other)
{
	if (other->GetTag() == "Enemy" || (other->GetTag() == "Bullet" && ((Bullet*)other)->GetVelY() < 0))
	{
		//Delete enemy & harm player
		SceneManager::GetInstance().GetCurrentScene()->DeleteObject(other);
		lives--;

		if (lives <= 0)
		{
			//Delete player
			SceneManager::GetInstance().GetCurrentScene()->DeleteObject(this);
			//Stop time
			TimeManager::GetInstance().SetGameOver(true);
		}
	}
}
#pragma endregion

/*****************************************************************************/