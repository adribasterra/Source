#pragma once
#include <Texture.h>
#include "Object.h"
/*
 * Paddle object class, extends Object
 */
class Paddle : public Object {

private:

	//float Object::x;
	//float Object::y;
	//float Object::width;
	//float Object::height;
	//float Object::rotation;
	//LTexture* Object::sprite;
	//SDL_Rect* Object::collider;
	//int Object::colliderType;

public:

	//Constructors
	Paddle() {};
	Paddle(float, float, float, float, float, LTexture*, SDL_Rect*);

	//Deallocate memory
	~Paddle();

	void Update();
};