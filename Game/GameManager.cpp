#include "GameManager.h"

//							Constructors
/*****************************************************************************/

GameManager::GameManager() {
	leftPlayerPoints = 0;
	rightPlayerPoints = 0;
}

//							Main methods
/*****************************************************************************/

void GameManager::AddPointLeft() {
	leftPlayerPoints++;
}
void GameManager::AddPointRight() {
	rightPlayerPoints++;
}