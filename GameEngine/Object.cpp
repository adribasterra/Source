#include "Object.h"

#pragma region Constructors

//							Constructors
/*****************************************************************************/

Object::Object()
{
	this->x = 0;
	this->y = 0;
	this->width = NULL;
	this->height = NULL;
	this->texture = NULL;
	this->rotation = NULL;
	this->collider = NULL;
	this->circleCollider = NULL;
	this->texture = NULL;
	colliderType = colliderTypes::none;
}

Object::Object(float x, float y)
{
	this->x = x;
	this->y = y;
	this->width = NULL;
	this->height = NULL;
	this->texture = NULL;
	this->rotation = NULL;
	this->collider = NULL;
	this->circleCollider = NULL;
	this->texture = NULL;
	colliderType = colliderTypes::none;
}

Object::Object(float x, float y, float width, float height, float rotation, LTexture* texture)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->texture = texture;
	this->rotation = rotation;
	this->collider = NULL;
	this->circleCollider = NULL;
	this->texture = texture;
	colliderType = colliderTypes::none;
}

Object::Object(float x, float y, float width, float height, float rotation, LTexture* texture, SDL_Rect* rectangle)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->rotation = rotation;
	this->texture = texture;
	this->collider = rectangle;
	this->circleCollider = NULL;
	colliderType = colliderTypes::rect;
}

Object::Object(float x, float y, float width, float height, float rotation, LTexture* texture, float* radius)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->rotation = rotation;
	this->texture = texture;
	this->collider = NULL;
	this->circleCollider = radius;
	colliderType = colliderTypes::circle;
}
Object::~Object()
{

}

#pragma endregion

#pragma region Main function

//								Main func
/*****************************************************************************/

void Object::Update() {
	printf("I'm updating\n");
}

#pragma endregion

#pragma region Getters

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
LTexture* Object::GetTexture()
{
	return texture;
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

#pragma endregion

#pragma region Setters

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
	texture = &textureAux;
}
void Object::SetCollider(SDL_Rect colliderAux) {
	collider = &colliderAux;
}

/*****************************************************************************/

#pragma endregion