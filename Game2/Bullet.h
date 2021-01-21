#pragma once

#include <Texture.h>
#include "Object.h"

/**
 * Bullet object class, extends Object
 */
class Bullet : public Object
{

private:

	float velX, velY;	//Velocity

	/*****************************************************************************/
public:

	//Maximum axis velocity of the ball
	static const int BULLET_VEL = 400;

	//Constructors
	Bullet();
	Bullet(float, float, float, float, float, LTexture*, SDL_Rect*, int);

	//Deallocate memory
	~Bullet() {};

	void Update(float);
	void OnCollisionEnter(Object*) {};

	//Getters
	float GetVelY();

	/*****************************************************************************/
};

