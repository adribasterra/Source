#pragma once

#include "Singleton.h"
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include <Texture.h>
#include <vector>
#include "SceneManager.h"

/**
 * Graphics Manager class
 */

class GraphicsManager : public Singleton<GraphicsManager>
{
	/*****************************************************************************/
	friend class Singleton<GraphicsManager>;
	/*****************************************************************************/

public:

	//Screen dimension constants
	static const int SCREEN_WIDTH = 640;
	static const int SCREEN_HEIGHT = 480;

	/*****************************************************************************/
private:
	//The window to be rendering to
	SDL_Window* mWindow;

	//The window renderer
	SDL_Renderer* mRenderer;

	std::vector<LTexture*> textures;


	//Private constructor to avoid more than one instance
	GraphicsManager();
	~GraphicsManager();

	/*****************************************************************************/
public:

	bool Init();

	LTexture* LoadTexture(std::string);

	//Getters
	SDL_Window* GetWindow();
	SDL_Renderer* GetRenderer();

	void Render();

	/*****************************************************************************/
};