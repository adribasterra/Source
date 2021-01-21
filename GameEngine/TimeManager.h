#pragma once

#include "Singleton.h"
#include "SDL.h"
#include "SDL_ttf.h"

/*
 * Time Manager class
 */
class TimeManager : public Singleton<TimeManager>
{
	/*****************************************************************************/
	friend class Singleton<TimeManager>;
	/*****************************************************************************/

private:

	int time;			//Total time
	int lastTimeRendered;
	int currentTime;
	int deltaTime;		//In miliseconds

	bool gameOver;

	int numFrames;
	float avgFPS;

	// Private constructor to avoid more than one instance
	TimeManager();
	~TimeManager() {};

	/*****************************************************************************/
public:

	void Update(void);

	//Getters & setters
	int GetDeltaTime();
	void SetGameOver(bool);

	/*****************************************************************************/
};