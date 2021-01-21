#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include <string>
#include <GraphicsManager.h>
#include "Singleton.h"

/**
 * Game Manager class
 */
class GameManager : public Singleton<GameManager>
{
	/*****************************************************************************/
	friend class Singleton<GameManager>;
	/*****************************************************************************/

private:

	//Points
	int leftPlayerPoints;
	int rightPlayerPoints;

	//Sounds
	std::string audioPathLeft;
	std::string audioPathRight;

	//LTexture gTextTexture;

	/*****************************************************************************/
public:

	//Constructors
	GameManager();
	~GameManager();
	
	void AddPointLeft();
	void AddPointRight();

	void AddAudios(std::string, std::string);

	//Getters
	int GetLeftPlayerPoints();
	int GetRightPlayerPoints();

	//Setters
	void SetText(std::string, SDL_Color);
	/*****************************************************************************/
};