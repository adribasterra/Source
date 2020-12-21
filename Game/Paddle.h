#pragma once
#include <Texture.h>
#include "Object.h"
/*
 * Paddle object class, extends Object
 */
class Paddle : Object {

	float Object::x;
	float Object::y;
	float Object::width;
	float Object::height;
	float Object::rotation;
	LTexture* Object::sprite;
	SDL_Rect* Object::collider;
	int Object::colliderType;

	//Constructors
	Paddle();
	Paddle(float, float, float, float, float, LTexture*, SDL_Rect*);

	//Deallocate memory
	~Paddle() {};

};