#pragma once

#include <Texture.h>
#include "Object.h"

/**
 * SpaceShip object class, extends Object
 */
class SpaceShip : public Object
{

protected:

	int velX, velY;		//Velocity

	float timer;
	float timeBetweenShoots;

	float bulletHeight;
	float bulletWidth;
	LTexture* bulletTexture;
	SDL_Rect* bulletCollider;

	void Shoot(int);

	/*****************************************************************************/
public:

	//Constructors
	SpaceShip();
	SpaceShip(float, float, float, float, float, LTexture*, SDL_Rect*);

	//Deallocate memory
	~SpaceShip() {};

	virtual void Update(float) {};
	virtual void HandleEvent(SDL_Event&) {};
	virtual void OnCollisionEnter(Object*) {};

	//Setters
	void SetBulletAttributes(float, float, LTexture*, SDL_Rect*);

	/*****************************************************************************/
};
