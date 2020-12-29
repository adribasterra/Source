#pragma once

#include "Singleton.h"
#include "SDL.h"
#include "SDL_image.h"
#include <Texture.h>
#include <vector>
#include "SceneManager.h"
/*
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
	//The window we'll be rendering to
	SDL_Window* mWindow = NULL;

	//The window renderer
	SDL_Renderer* mRenderer = NULL;

	std::vector<LTexture> textures;

	// Private constructor to avoid more than one instance
	GraphicsManager() {};
	~GraphicsManager();

	/*****************************************************************************/
public:

	bool Init(void);

	LTexture* LoadTexture(std::string);

	void Update(void);

	SDL_Window* GetWindow(void) { return mWindow; }

	SDL_Renderer* GetRenderer(void) { return mRenderer; }

	void Render();

};