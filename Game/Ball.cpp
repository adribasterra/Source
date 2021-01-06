#include "Ball.h"
#include "GraphicsManager.h"
#include "InputManager.h"

//							Constructors
/*****************************************************************************/

Ball::Ball(float x, float y, float width, float height, float rotation, LTexture* texture, float* radius)
{
	//Object::Object(x, y, width, height, rotation, texture, radius);

	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->rotation = rotation;
	this->texture = texture;
	this->circleCollider = radius;
	colliderType = colliderTypes::circle;
}

Ball::~Ball()
{
	Object::~Object();
}

//								Main func
/*****************************************************************************/

void Ball::Update() {
	printf("Virtual override of Object update in Ball");
}

void Ball::HandleEvent(SDL_Event& e)
{
	//If a key was pressed
	if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
	{
		//Adjust the velocity
		switch (e.key.keysym.sym)
		{
			case SDLK_UP: mVelY -= BALL_VEL; break;
			case SDLK_DOWN: mVelY += BALL_VEL; break;
			case SDLK_LEFT: mVelX -= BALL_VEL; break;
			case SDLK_RIGHT: mVelX += BALL_VEL; break;
		}
	}
	//If a key was released
	else if (e.type == SDL_KEYUP && e.key.repeat == 0)
	{
		//Adjust the velocity
		switch (e.key.keysym.sym)
		{
			case SDLK_UP: mVelY += BALL_VEL; break;
			case SDLK_DOWN: mVelY -= BALL_VEL; break;
			case SDLK_LEFT: mVelX += BALL_VEL; break;
			case SDLK_RIGHT: mVelX -= BALL_VEL; break;
		}
	}
}

void Ball::Move()
{
	mVelX = 0;
	mVelY = 0;
	if (InputManager::GetInstance().GetKey(SDL_SCANCODE_UP)) {
		mVelY -= BALL_VEL;
	}
	if (InputManager::GetInstance().GetKey(SDL_SCANCODE_DOWN)) {
		mVelY += BALL_VEL;
	}
	if (InputManager::GetInstance().GetKey(SDL_SCANCODE_LEFT)) {
		mVelX -= BALL_VEL;
	}
	if (InputManager::GetInstance().GetKey(SDL_SCANCODE_RIGHT)) {
		mVelX += BALL_VEL;
	}

	//Move the dot left or right
	this->x += mVelX;

	//If the dot went too far to the left or right
	if ((this->x < 0) || (this->x + this->texture->getWidth() > GraphicsManager::SCREEN_WIDTH))
	{
		//Move back
		this->x -= mVelX;
	}

	//Move the dot up or down
	this->y += mVelY;

	//If the dot went too far up or down
	if ((this->y < 0) || (this->y + this->texture->getHeight() > GraphicsManager::SCREEN_HEIGHT))
	{
		//Move back
		this->y -= mVelY;
	}
}