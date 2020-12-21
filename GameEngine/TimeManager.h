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

	int numFrames;
	float avgFPS;

	// Private constructor to avoid more than one instance
	TimeManager() {};
	~TimeManager() {};

	/*****************************************************************************/
public:

	void Update(void);

	int GetDeltaTime();

};