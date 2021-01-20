#include "SDL.h"
#include "SDL_image.h"
#include <string>
#include <GraphicsManager.h>
#include "Singleton.h"

#pragma once
/*
 * Game Manager class
 */
class GameManager : public Singleton<GameManager>
{
	/*****************************************************************************/
	friend class Singleton<GameManager>;
	/*****************************************************************************/

private:

	int leftPlayerPoints;
	int rightPlayerPoints;
	std::string audioPathLeft;
	std::string audioPathRight;
	//LTexture gTextTexture;

public:

	//Constructors
	GameManager();
	~GameManager();
	
	void AddPointLeft();
	void AddPointRight();

	void AddAudios(std::string, std::string);

	int GetLeftPlayerPoints();
	int GetRightPlayerPoints();

	void SetText(std::string, SDL_Color);
};