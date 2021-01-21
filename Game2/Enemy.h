#pragma once

#include <Texture.h>
#include "Object.h"

/**
 * Enemy object class, extends Object
 */
class Enemy : public Object
{

private:

	int velX, velY;		//Velocity
	int type;

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
