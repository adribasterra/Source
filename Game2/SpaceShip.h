#pragma once
#include <Texture.h>
#include "Object.h"

class SpaceShip : public Object
{
private:

	int velX, velY;	// Velocity
	float timmer = 0.0;
	int life;
	float timeBetweenShoots = 1.0;
	float bulletHeight;
	float bulletWidth;
	LTexture* bulletTexture;
	SDL_Rect* bulletCollider;
	void ResetPosition();
	void Shoot();

public:

	//Maximum axis velocity of the ball
	static const int SPACESHIP_VEL = 200;

	//Constructors
	SpaceShip();
	SpaceShip(float, float, float, float, float, LTexture*, SDL_Rect*);

	//Deallocate memory
	~SpaceShip();

	void setBulletAttributes(float,float,LTexture*,SDL_Rect*);
	void Update(float);
	void HandleEvent(SDL_Event&);
	void OnCollisionEnter(Object*);
};

