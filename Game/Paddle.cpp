#include "Paddle.h"

//							Constructors
/*****************************************************************************/

Paddle::Paddle(float x, float y, float width, float height, float rotation, LTexture* texture, SDL_Rect* rectangle)
{
	Object::Object(x, y, width, height, rotation, texture, rectangle);
	
	//this->x = x;
	//this->y = y;
	//this->width = width;
	//this->height = height;
	//this->rotation = rotation;
	//this->sprite = texture;
	//this->collider = rectangle;
	//colliderType = colliderTypes::rect;
}

Paddle::~Paddle()
{
	Object::~Object();
}

//								Main func
/*****************************************************************************/

void Object::Update() {
	printf("Virtual override of Object update in Paddle");
}
