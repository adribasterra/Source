#pragma once
#include <Texture.h>
#include "Object.h"

class Bullet : public Object
{
private:

	int velX, velY;	// Velocity
	void ResetPosition() {};

public:

	//Maximum axis velocity of the ball
	static const int BULLET_VEL = 10;

	//Constructors
	Bullet();
	Bullet(float, float, float, float, float, LTexture*, SDL_Rect*, int);

	//Deallocate memory
	~Bullet();

	void Update(float);
	void OnCollisionEnter(Object*) {};
};

