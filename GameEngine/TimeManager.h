#pragma once

#include "Singleton.h"
#include "SDL.h"

/*
 * Time Manager class
 */
class TimeManager : public Singleton<TimeManager>
{
	/*****************************************************************************/
	friend class Singleton<TimeManager>;
	/*****************************************************************************/

private:

	float deltaTime;
	float time;

	// Private constructor to avoid more than one instance
	TimeManager() {};
	~TimeManager() {};

	/*****************************************************************************/

public:

	void Update(void);

	/*****************************************************************************/

};