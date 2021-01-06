#pragma once
#include <Texture.h>
#include "Object.h"
/*
 * Paddle object class, extends Object
 */
class Paddle : public Object {

private:

	int velX, velY;	// Velocity

	//Controls
	SDL_Scancode upKey;
	SDL_Scancode downKey;

public:

	//Maximum axis velocity of the paddle
	static const int PADDLE_VEL = 10;
	
	//Constructors
	Paddle() {};
	Paddle(float, float, float, float, float, LTexture*, SDL_Rect*);

	//Deallocate memory
	~Paddle();

	void Update();
	void SetControls(SDL_Scancode, SDL_Scancode);
	void HandleEvent(SDL_Event&);

	void Move();
};