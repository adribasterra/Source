#include "TimeManager.h"


//								Main function
/*****************************************************************************/

void TimeManager::Update(void)
{
	//Set deltaTime depending on the last time rendered.
	time += deltaTime;
	currentTime = SDL_GetTicks(); //miliseconds
	deltaTime = currentTime - lastTimeRendered;

	//Calculate and correct fps
	avgFPS = numFrames / (SDL_GetTicks() / 1000.f);
	if (avgFPS > 2000000)
	{
		avgFPS = 0;
	}

	numFrames++;
	lastTimeRendered = currentTime;
}

int TimeManager::GetDeltaTime()
{
	return deltaTime;
}

/*****************************************************************************/
