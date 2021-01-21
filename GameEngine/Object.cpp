#include "Object.h"

//							Constructors
/*****************************************************************************/
#pragma region Constructors

Object::Object()
{
	this->centeredX = 0;
	this->centeredY = 0;
	this->width = NULL;
	this->height = NULL;
	this->texture = NULL;
	this->rotation = NULL;
	this->collider = NULL;
	this->circleCollider = NULL;
	this->texture = NULL;
	colliderType = colliderTypes::none;
	tag = "";
}

Object::Object(float x, float y)
{
	this->centeredX = x;
	this->centeredY = y;
	this->width = NULL;
	this->height = NULL;
	this->texture = NULL;
	this->rotation = NULL;
	this->collider = NULL;
	this->circleCollider = NULL;
	this->texture = NULL;
	colliderType = colliderTypes::none;
	tag = "";
}

Object::Object(float x, float y, float width, float height, float rotation, LTexture* texture)
{
	this->centeredX = x;
	this->centeredY = y;
	this->width = width;
	this->height = height;
	this->texture = texture;
	this->rotation = rotation;
	this->collider = NULL;
	this->circleCollider = NULL;
	this->texture = texture;
	colliderType = colliderTypes::none;
	tag = "";
}

Object::Object(float x, float y, float width, float height, float rotation, LTexture* texture, SDL_Rect* rectangle, std::string tag)
{
	this->centeredX = x;
	this->centeredY = y;
	this->width = width;
	this->height = height;
	this->rotation = rotation;
	this->texture = texture;
	this->collider = rectangle;
	this->circleCollider = NULL;
	colliderType = colliderTypes::rect;
	this->tag = tag;
}

Object::Object(float x, float y, float width, float height, float rotation, LTexture* texture, float* radius, std::string tag)
{
	this->centeredX = x;
	this->centeredY = y;
	this->width = width;
	this->height = height;
	this->rotation = rotation;
	this->texture = texture;
	this->collider = NULL;
	this->circleCollider = radius;
	colliderType = colliderTypes::circle;
	this->tag = tag;
}
#pragma endregion

//								Getters
/*****************************************************************************/
#pragma region Getters

float Object::GetX()
{
	return centeredX;
}
float Object::GetY()
{
	return centeredY;
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
std::string Object::GetTag()
{
	return tag;
}
#pragma endregion

//								Setters
/*****************************************************************************/
#pragma region Setters

void Object::SetPosition(float xAux, float yAux)
{
	centeredX = xAux;
	centeredY = yAux;
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
void Object::SetCollider(SDL_Rect colliderAux)
{
	collider = &colliderAux;
}

void Object::SetTag(std::string tag)
{
	this->tag = tag;
}
#pragma endregion

/*****************************************************************************/
