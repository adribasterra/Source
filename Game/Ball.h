#pragma once
#include <Texture.h>
#include "Object.h"
/*
 * Ball object class, extends Object
 */
class Ball : Object {

	float Object::x;
	float Object::y;
	float Object::width;
	float Object::height;
	float Object::rotation;
	LTexture* Object::sprite;
	float* Object::circleCollider;
	int Object::colliderType;

	//Constructors
	Ball();
	Ball(float, float, float, float, float, LTexture*, float*);

	//Deallocate memory
	~Ball() {};

};