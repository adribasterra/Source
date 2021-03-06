#pragma once

#include <Texture.h>
#include "SpaceShip.h"

/**
 * Enemy object class, extends SpaceShip
 */
class Enemy : public SpaceShip
{

private:

	int type;

	/*****************************************************************************/
public:

	//Maximum axis velocity of the ball
	static const int ENEMY_VEL = 150;

	//Constructors
	Enemy();
	Enemy(float, float, float, float, float, LTexture*, SDL_Rect*, int);

	//Deallocate memory
	~Enemy() {};

	void Update(float);
	void OnCollisionEnter(Object*);
	//Setters
	void SetBulletAttributes(float, float, LTexture*, SDL_Rect*);

	/*****************************************************************************/
};

enum enemyType : int {	//Unscoped enum
	normal = 0,
	zigzag = 1,
	shooting = 2
};
