#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include <stdio.h>
#include <string>
#include <cmath>

/*
 * Texture wrapper class
 */
class LTexture
{
public:
  //Initializes variables
  LTexture();

  //Deallocates memory
  ~LTexture();

  //Loads image at specified path
  bool loadFromFile(std::string path);

#ifdef _SDL_TTF_H
  //Creates image from font string
  bool loadFromRenderedText(std::string textureText, SDL_Color textColor);
#endif

  //Deallocates texture
  void free();

  //Setters
  void setColor(Uint8 red, Uint8 green, Uint8 blue);	//Color modulation
  void setBlendMode(SDL_BlendMode blending);			//Blending
  void setAlpha(Uint8 alpha);							//Alpha modulation
  void setFilePath(std::string filePath);				//File path

  //Getters
  int getWidth();
  int getHeight();
  std::string getFilePath();
  SDL_Texture* getTexture();

  //Renders texture at given point
  void render(int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);

  /*****************************************************************************/
private:
  //The actual hardware texture
  SDL_Texture* mTexture;

  //File path
  std::string filePath;

  //Image dimensions
  int mWidth;
  int mHeight;

  //Globally used font
  TTF_Font* gFont = NULL;

  /*****************************************************************************/
};