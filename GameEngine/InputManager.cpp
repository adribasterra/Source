#include "InputManager.h"

//								Constructor
/*****************************************************************************/
#pragma region Constructor

InputManager::InputManager()
{
	mCurrentKeyStates = 0;
}
#pragma endregion

//								Main function
/*****************************************************************************/
#pragma region Main function

void InputManager::Update()
{
	mCurrentKeyStates = SDL_GetKeyboardState(NULL);
}
#pragma endregion

//								Getters
/*****************************************************************************/
#pragma region Getters

bool InputManager::GetKey(int scanCode)
{
	return mCurrentKeyStates[scanCode] != 0;
}
#pragma endregion

/*****************************************************************************/