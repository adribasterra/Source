#pragma once
#include <Texture.h>
#include "Object.h"

class Enemy : public Object
{
private:

	int velX, velY;	// Velocity
	int type;
	float timmer = 0.0;
	float timeBetweenShoots = 2.5;

	float bulletHeight;
	float bulletWidth;
	LTexture* bulletTexture;
	SDL_Rect* bulletCollider;

	void ResetPosition() {};

public:

	//Maximum axis velocity of the ball
	static const int ENEMY_VEL = 150;

	//Constructors
	Enemy();
	Enemy(float, float, float, float, float, LTexture*, SDL_Rect*,int);

	//Deallocate memory
	~Enemy();

	void setBulletAttributes(float, float, LTexture*, SDL_Rect*);

	void Update(float);
	void OnCollisionEnter(Object*);
};

enum enemyType : int {	//Unscoped enum
	normal = 0,
	zigzag = 1,
	shooting = 2
};
