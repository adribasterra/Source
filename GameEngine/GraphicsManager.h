#pragma once

#include "Singleton.h"
#include "SDL.h"
#include "SDL_image.h"

/*
 * Graphics Manager class
 */
class GraphicsManager :public Singleton<GraphicsManager>
{
	/*****************************************************************************/
	friend class Singleton<GraphicsManager>;
	/*****************************************************************************/

public:
	//Screen dimension constants
	static const int SCREEN_WIDTH  = 640;
	static const int SCREEN_HEIGHT = 480;

private:
	//The window we'll be rendering to
	SDL_Window *mWindow = NULL;
  
	//The window renderer
	SDL_Renderer *mRenderer = NULL;


	// Private constructor to avoid more than one instance
	GraphicsManager() {};
	~GraphicsManager();

	/*****************************************************************************/

public:

	bool Init(void);
  
	void Update(void);

	SDL_Window *GetWindow(void) { return mWindow; }

	SDL_Renderer *GetRenderer(void) { return mRenderer; }

	/*****************************************************************************/

};