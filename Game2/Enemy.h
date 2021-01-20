#pragma once
#include <Texture.h>
#include "Object.h"

class Enemy : public Object
{
private:

	int velX, velY;	// Velocity
	int type;
	void ResetPosition() {};

public:

	//Maximum axis velocity of the ball
	static const int ENEMY_VEL = 10;

	//Constructors
	Enemy();
	Enemy(float, float, float, float, float, LTexture*, SDL_Rect*,int);

	//Deallocate memory
	~Enemy();

	void Update(float);
	void OnCollisionEnter(Object*) {};
};

enum enemyType : int {	//Unscoped enum
	normal = 0,
	zigzag = 1,
	shooting = 2
};
