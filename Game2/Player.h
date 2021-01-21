#pragma once

#include <Texture.h>
#include "SpaceShip.h"

/**
 * Player object class, extends SpaceShip
 */
class Player : public SpaceShip
{

private:

	int lives;

	/*****************************************************************************/
public:

	//Maximum axis velocity of the ball
	static const int SPACESHIP_VEL = 200;

	//Constructors
	Player();
	Player(float, float, float, float, float, LTexture*, SDL_Rect*);

	//Deallocate memory
	~Player() {};

	void Update(float);
	void HandleEvent(SDL_Event&);
	void OnCollisionEnter(Object*);
	//Setters
	void SetBulletAttributes(float, float, LTexture*, SDL_Rect*);

	/*****************************************************************************/
};
