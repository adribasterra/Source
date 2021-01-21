#include "GameManager.h"
#include "AudioManager.h"

//							Constructors
/*****************************************************************************/
#pragma region Constructors

GameManager::GameManager()
{
	leftPlayerPoints = 0;
	rightPlayerPoints = 0;
}

GameManager::~GameManager()
{
	//gTextTexture.free();
}
#pragma endregion

//							Main functions
/*****************************************************************************/
#pragma region Main functions

void GameManager::AddPointLeft()
{
	leftPlayerPoints++;
	AudioManager::GetInstance().PlayAudio(audioPathLeft);

}
void GameManager::AddPointRight()
{
	rightPlayerPoints++;
	AudioManager::GetInstance().PlayAudio(audioPathRight);
}
#pragma endregion

//							Getters
/*****************************************************************************/
#pragma region Getters

int GameManager::GetLeftPlayerPoints()
{
	return leftPlayerPoints;
}

int GameManager::GetRightPlayerPoints()
{
	return rightPlayerPoints;
}
#pragma endregion

//							Setters
/*****************************************************************************/
#pragma region Setters

void GameManager::SetText(std::string text, SDL_Color textColor)
{
	//if (!gTextTexture.loadFromRenderedText(text, textColor))
	{
		printf("Failed to render text texture!\n");
	}
}
#pragma endregion

//							Others
/*****************************************************************************/
#pragma region Others

void GameManager::AddAudios(std::string left, std::string right)
{
	audioPathLeft = left;
	audioPathRight = right;
}
#pragma endregion

/*****************************************************************************/