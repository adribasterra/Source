#include "GameManager.h"
#include "AudioManager.h"
//							Constructors
/*****************************************************************************/

GameManager::GameManager(std::string left, std::string right)
{
	leftPlayerPoints = 0;
	rightPlayerPoints = 0;
	audioPathLeft = left;
	audioPathRight = right;
}

GameManager::~GameManager()
{
	//gTextTexture.free();
}

//							Main methods
/*****************************************************************************/

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

int GameManager::GetLeftPlayerPoints()
{
	return leftPlayerPoints;
}
int GameManager::GetRightPlayerPoints()
{
	return rightPlayerPoints;
}

void GameManager::SetText(std::string text, SDL_Color textColor)
{
	//if (!gTextTexture.loadFromRenderedText(text, textColor))
	{
		printf("Failed to render text texture!\n");
	}
}