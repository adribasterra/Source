#include "Player.h"
#include "GraphicsManager.h"
#include "TimeManager.h"
#include "InputManager.h"
#include "Bullet.h"
//							Constructors
/*****************************************************************************/
#pragma region Constructors
Player::Player()
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

Player::Player(float x, float y, float width, float height, float rotation, LTexture* texture, SDL_Rect* rectangle) : SpaceShip()
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

void Player::Update(float dt)
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
		Shoot(1);
		timer = 0;
	}

	//Update movement in X axis
	centeredX += velX * dt;

	//Check screen borders
	if (centeredX + width / 2 < 0)
	{
		//Move back
		centeredX += SPACESHIP_VEL * dt;
	}
	else if (centeredX + width / 2 > GraphicsManager::SCREEN_WIDTH)
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

void Player::HandleEvent(SDL_Event& e)
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
void Player::SetBulletAttributes(float width, float height, LTexture* texture, SDL_Rect* collider)
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
void Player::OnCollisionEnter(Object* other)
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