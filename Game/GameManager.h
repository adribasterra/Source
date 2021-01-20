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
	std::string audioPathLeft;
	std::string audioPathRight;
	//LTexture gTextTexture;

public:

	//Constructors
	GameManager(std::string, std::string);
	~GameManager();
	
	void AddPointLeft();
	void AddPointRight();

	int GetLeftPlayerPoints();
	int GetRightPlayerPoints();

	void SetText(std::string, SDL_Color);
};