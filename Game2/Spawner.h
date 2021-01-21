#pragma once

#include <Texture.h>
#include "Object.h"

/**
 * Spawner object class, extends Object
 */
class Spawner : public Object
{

private:

	float timer;
	float timeBetweenSpawns;

	float bulletHeight;
	float bulletWidth;
	LTexture* bulletTexture;
	SDL_Rect* bulletCollider;

	/*****************************************************************************/
public:

	//Constructors
	Spawner();
	Spawner(float, float, float, LTexture*, SDL_Rect*);

	//Deallocate memory
	~Spawner() {};

	void Update(float);

	//Setters
	void SetBulletAttributes(float, float, LTexture*, SDL_Rect*);

	/*****************************************************************************/
};
