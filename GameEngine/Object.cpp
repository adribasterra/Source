#include "Object.h"

//							Constructors
/*****************************************************************************/

Object::Object()
{
	x = 0;
	y = 0;
	colliderType = colliderTypes::none;
}
Object::Object(float x, float y)
{
	this->x = x;
	this->y = y;
	colliderType = colliderTypes::none;
}
Object::Object(float x, float y, float width, float height, float rotation, LTexture* texture)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->sprite = texture;
	this->rotation = rotation;
	this->sprite = texture;
	colliderType = colliderTypes::none;
}
Object::Object(float x, float y, float width, float height, float rotation, LTexture* texture, SDL_Rect* rectangle)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->rotation = rotation;
	this->sprite = texture;
	this->collider = rectangle;
	colliderType = colliderTypes::rect;
}
Object::Object(float x, float y, float width, float height, float rotation, LTexture* texture, float* radius)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->rotation = rotation;
	this->sprite = texture;
	this->circleCollider = radius;
	colliderType = colliderTypes::circle;
}
Object::~Object()
{

}

//								Main func
/*****************************************************************************/

void Object::Update() {
	printf("I'm updating\n");
}

//								Getters
/*****************************************************************************/

float Object::GetX()
{
	return x;
}
float Object::GetY()
{
	return y;
}
float Object::GetWidth()
{
	return width;
}
float Object::GetHeight()
{
	return height;
}
float Object::GetRotation()
{
	return rotation;
}
LTexture* Object::GetSprite()
{
	return sprite;
}
SDL_Rect* Object::GetCollider()
{
	return collider;
}
int Object::GetTypeCollision()
{
	return colliderType;
}
float* Object::GetRadius()
{
	return circleCollider;
}

//								Setters
/*****************************************************************************/

void Object::SetPosition(float xAux, float yAux)
{
	x = xAux;
	y = yAux;
}
void Object::SetSize(float widthAux, float heightAux)
{
	width = widthAux;
	height = heightAux;
}
void Object::SetRotation(float rotationAux)
{
	rotation = rotationAux;
}
void Object::SetSprite(LTexture textureAux)
{
	sprite = &textureAux;
}
void Object::SetCollider(SDL_Rect colliderAux) {
	collider = &colliderAux;
}

/*****************************************************************************/
