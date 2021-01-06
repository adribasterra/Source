#pragma once
#include <Texture.h>
#include "Object.h"
/*
 * Ball object class, extends Object
 */
class Ball : public Object {

private:

	int mVelX, mVelY;	// Velocity 

public:

	//Maximum axis velocity of the ball
	static const int BALL_VEL = 10;

	//Constructors
	Ball() {};
	Ball(float, float, float, float, float, LTexture*, float*);

	//Deallocate memory
	~Ball();

	void Update();

	void HandleEvent(SDL_Event&);

	void Move();
};