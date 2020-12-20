#pragma once

#include "Singleton.h"
#include "SDL.h"

/*
 * Input Manager class
 */
class InputManager : public Singleton<InputManager>
{
	/*****************************************************************************/
	friend class Singleton<InputManager>;
	/*****************************************************************************/

private:

	// Keyboard state
	const Uint8* mCurrentKeyStates; // must to be a vector of inputs?

	// Private constructor to avoid more than one instance
	InputManager() {};

	/*****************************************************************************/
public:

	void Update(void);

	bool GetKey(int scanCode);

};