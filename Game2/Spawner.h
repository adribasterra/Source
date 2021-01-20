#pragma once
#include <Texture.h>
#include "Object.h"

class Spawner : public Object
{
private:

	float timmer = 0.0;
	float timeUntileSpawn;

public:

	//Constructors
	Spawner();
	Spawner(float,LTexture*, SDL_Rect*);

	//Deallocate memory
	~Spawner();

	void Update(float);
};
