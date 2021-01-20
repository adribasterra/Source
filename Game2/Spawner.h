#pragma once
#include <Texture.h>
#include "Object.h"

class Spawner : public Object
{
private:

	float timmer = 0.0;
	float timeUntileSpawn;

	float bulletHeight;
	float bulletWidth;
	LTexture* bulletTexture;
	SDL_Rect* bulletCollider;

public:

	//Constructors
	Spawner();
	Spawner(float, float, float, LTexture*, SDL_Rect*);

	//Deallocate memory
	~Spawner();

	void setBulletAttributes(float, float, LTexture*, SDL_Rect*);
	void Update(float);
};
