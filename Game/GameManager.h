#include "SDL.h"
#include "SDL_image.h"
#include <string>
#include <GraphicsManager.h>

#pragma once
/*
 * Game Manager class
 */
class GameManager {

private:

	int leftPlayerPoints;
	int rightPlayerPoints;

	//LTexture gTextTexture;

public:

	//Constructors
	GameManager();
	~GameManager();
	
	void AddPointLeft();
	void AddPointRight();

	int GetLeftPlayerPoints();
	int GetRightPlayerPoints();

	void SetText(std::string, SDL_Color);
};