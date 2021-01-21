#pragma once

#include <Texture.h>
#include "Object.h"

/**
 * SpaceShip object class, extends Object
 */
class SpaceShip : public Object
{

private:

	int velX, velY;		//Velocity
	int lives;

	float timer;
	float timeBetweenShoots;

	float bulletHeight;
	float bulletWidth;
	LTexture* bulletTexture;
	SDL_Rect* bulletCollider;

	void Shoot();

	/*****************************************************************************/
public:

	//Maximum axis velocity of the ball
	static const int SPACESHIP_VEL = 200;

	//Constructors
	SpaceShip();
	SpaceShip(float, float, float, float, float, LTexture*, SDL_Rect*);

	//Deallocate memory
	~SpaceShip() {};

	void Update(float);
	void HandleEvent(SDL_Event&);
	void OnCollisionEnter(Object*);

	//Setters
	void SetBulletAttributes(float, float, LTexture*, SDL_Rect*);

	/*****************************************************************************/
};
