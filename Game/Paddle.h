#pragma once
#include <Texture.h>
#include "Object.h"
/*
 * Paddle object class, extends Object
 */
class Paddle : public Object {

private:

	int velX, velY;	// Velocity

	enum ControlKeys : int
	{
		up = SDL_SCANCODE_UP,
		down = SDL_SCANCODE_DOWN,
		//left = SDL_SCANCODE_LEFT,
		//right = SDL_SCANCODE_RIGHT
	};

public:

	//Maximum axis velocity of the paddle
	static const int PADDLE_VEL = 10;
	
	//Constructors
	Paddle() {};
	Paddle(float, float, float, float, float, LTexture*, SDL_Rect*);

	//Deallocate memory
	~Paddle();

	void Update();

	void HandleEvent(SDL_Event&);

	void Move();
};