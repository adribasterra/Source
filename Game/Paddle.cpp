#include "Paddle.h"
#include "GraphicsManager.h"
#include "InputManager.h"

//							Constructors
/*****************************************************************************/
#pragma region Constructors

Paddle::Paddle()
{
	velX = 0;
	velY = 0;
	upKey = SDL_SCANCODE_UNKNOWN;
	downKey = SDL_SCANCODE_UNKNOWN;
}

Paddle::Paddle(float x, float y, float width, float height, float rotation, LTexture* texture, SDL_Rect* rectangle) : Object()
{
	//Inherited from Object
	this->centeredX = x;
	this->centeredY = y;
	this->width = width;
	this->height = height;
	this->rotation = rotation;
	this->texture = texture;
	this->collider = rectangle;
	this->tag = "Paddle";
	colliderType = colliderTypes::rect;

	//Own
	velX = 0;
	velY = 0;
	upKey = SDL_SCANCODE_UNKNOWN;
	downKey = SDL_SCANCODE_UNKNOWN;
}
#pragma endregion

//							Main functions
/*****************************************************************************/
#pragma region Main functions

void Paddle::Update(float dt)
{
	velX = 0;
	velY = 0;

	//Handle key inputs
	if (InputManager::GetInstance().GetKey(upKey)) {
		velY -= PADDLE_VEL;
	}
	if (InputManager::GetInstance().GetKey(downKey)) {
		velY += PADDLE_VEL;
	}

	//Update movement in Y axis
	centeredY += velY * dt;

	//Check screen borders
	if (centeredY < 0)
	{
		//Move back
		centeredY += PADDLE_VEL * dt;
	}
	else if (centeredY + height > GraphicsManager::SCREEN_HEIGHT)
	{
		centeredY -= PADDLE_VEL * dt;
	}
}

void Paddle::HandleEvent(SDL_Event& e)
{
	//On key pressed
	if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
	{
		//Adjust velocity
		switch (e.key.keysym.sym)
		{
			case SDLK_UP:		velY -= PADDLE_VEL; break;
			case SDLK_DOWN:		velY += PADDLE_VEL; break;
		}
	}
	//On key released
	else if (e.type == SDL_KEYUP && e.key.repeat == 0)
	{
		//Adjust velocity
		switch (e.key.keysym.sym)
		{
			case SDLK_UP:		velY += PADDLE_VEL; break;
			case SDLK_DOWN:		velY -= PADDLE_VEL; break;
		}
	}
}
#pragma endregion

//							Setters
/*****************************************************************************/
#pragma region Setters

void Paddle::SetControls(SDL_Scancode upKey, SDL_Scancode downKey)
{
	this->upKey = upKey;
	this->downKey = downKey;
}
#pragma endregion

/*****************************************************************************/
