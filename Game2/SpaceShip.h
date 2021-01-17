#pragma once
#include <Texture.h>
#include "Object.h"

class SpaceShip : public Object
{
private:

	int velX, velY;	// Velocity
	void ResetPosition() {};
	void Shoot() {};

public:

	//Maximum axis velocity of the ball
	static const int SPACESHIP_VEL = 5;

	//Constructors
	SpaceShip();
	SpaceShip(float, float, float, float, float, LTexture*, SDL_Rect*);

	//Deallocate memory
	~SpaceShip();

	void Update(float);
	void HandleEvent(SDL_Event&);
	void OnCollisionEnter(Object*) {};
};

