#include "Paddle.h"
#include "GraphicsManager.h"
#include "InputManager.h"

//							Constructors
/*****************************************************************************/

Paddle::Paddle(float x, float y, float width, float height, float rotation, LTexture* texture, SDL_Rect* rectangle) : Object()
{
	//__super::Object(x, y, width, height, rotation, texture, rectangle);

	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->rotation = rotation;
	this->texture = texture;
	this->collider = rectangle;
	colliderType = colliderTypes::rect;
}

Paddle::~Paddle()
{
	Object::~Object();
}

//								Main func
/*****************************************************************************/

void Paddle::Update() {
	printf("Virtual override of Object update in Paddle");
}

void Paddle::HandleEvent(SDL_Event& e)
{
	//If a key was pressed
	if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
	{
		//Adjust the velocity
		switch (e.key.keysym.sym)
		{
		case SDLK_UP: velY -= PADDLE_VEL; break;
		case SDLK_DOWN: velY += PADDLE_VEL; break;
		case SDLK_LEFT: velX -= PADDLE_VEL; break;
		case SDLK_RIGHT: velX += PADDLE_VEL; break;
		}
	}
	//If a key was released
	else if (e.type == SDL_KEYUP && e.key.repeat == 0)
	{
		//Adjust the velocity
		switch (e.key.keysym.sym)
		{
		case SDLK_UP: velY += PADDLE_VEL; break;
		case SDLK_DOWN: velY -= PADDLE_VEL; break;
		case SDLK_LEFT: velX += PADDLE_VEL; break;
		case SDLK_RIGHT: velX -= PADDLE_VEL; break;
		}
	}
}

void Paddle::Move()
{
	velX = 0;
	velY = 0;

	if (InputManager::GetInstance().GetKey(ControlKeys::up)) {
		velY -= PADDLE_VEL;
	}
	if (InputManager::GetInstance().GetKey(ControlKeys::down)) {
		velY += PADDLE_VEL;
	}
	//if (InputManager::GetInstance().GetKey(ControlKeys::left)) {
	//	velX -= PADDLE_VEL;
	//}
	//if (InputManager::GetInstance().GetKey(ControlKeys::right)) {
	//	velX += PADDLE_VEL;
	//}

	//Move the dot left or right
	x += velX;

	//If the dot went too far to the left or right
	if ((x < 0) || (x + this->texture->getWidth() > GraphicsManager::SCREEN_WIDTH))
	{
		//Move back
		x -= velX;
	}

	//Move the dot up or down
	y += velY;

	//If the dot went too far up or down
	if ((y < 0) || (y + this->texture->getHeight() > GraphicsManager::SCREEN_HEIGHT))
	{
		//Move back
		y -= velY;
	}
}


