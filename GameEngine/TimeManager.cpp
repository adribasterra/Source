#include "TimeManager.h"

TimeManager::TimeManager()
{
	gameOver = false;
}

//								Main function
/*****************************************************************************/

void TimeManager::Update(void)
{
	if (!gameOver) {
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
	else {
		deltaTime = 0;
	}
}

int TimeManager::GetDeltaTime()
{
	return deltaTime;
}

void TimeManager::GameOver()
{
	this->gameOver = true;
}

/*****************************************************************************/
