#include "TimeManager.h"

//								Constructor
/*****************************************************************************/
#pragma region Constructor

TimeManager::TimeManager()
{
	time = 0;
	lastTimeRendered = 0;
	currentTime = 0;
	deltaTime = 0;

	gameOver = false;

	numFrames = 0;
	avgFPS = 0;
}
#pragma endregion

//								Main function
/*****************************************************************************/
#pragma region Main function

void TimeManager::Update(void)
{
	if (!gameOver) {
		//Set deltaTime depending on the last time rendered
		time += deltaTime;
		currentTime = SDL_GetTicks();	//In miliseconds
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
#pragma endregion

//								Getters & setters
/*****************************************************************************/
#pragma region Getters & setters

int TimeManager::GetDeltaTime()
{
	return deltaTime;
}

void TimeManager::SetGameOver(bool gameOver)
{
	this->gameOver = gameOver;
}
#pragma endregion

/*****************************************************************************/
