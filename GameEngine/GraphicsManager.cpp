#include "GraphicsManager.h"
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <string>

//								Constructors
/*****************************************************************************/
#pragma region Constructors

GraphicsManager::GraphicsManager()
{
    mWindow = NULL;
    mRenderer = NULL;

    textures = std::vector<LTexture*>();
    textures.reserve(10);
}

GraphicsManager::~GraphicsManager()
{
    //Destroy window	
    SDL_DestroyRenderer(mRenderer);
    SDL_DestroyWindow(mWindow);
    mWindow = NULL;
    mRenderer = NULL;

    //Quit SDL subsystems
    //TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}
#pragma endregion

//								Initialize
/*****************************************************************************/
#pragma region Initialize

bool GraphicsManager::Init()
{
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
        success = false;
    }
    else
    {
        //Set texture filtering to linear
        if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
        {
            printf("Warning: Linear texture filtering not enabled!\n");
        }

        //Create window
        mWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (mWindow == NULL)
        {
            printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
            success = false;
        }
        else {
            //Create vsynced renderer for window
            mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if (mRenderer == NULL)
            {
                printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
                success = false;
            }
            else {
                //Initialize renderer color
                SDL_SetRenderDrawColor(mRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

                //Initialize PNG loading
                int imgFlags = IMG_INIT_PNG;
                if (!(IMG_Init(imgFlags) & imgFlags))
                {
                    const char* error = IMG_GetError();
                    printf("SDL_image could not initialize! SDL_image Error: %s\n", error);
                    success = false;
                }

                //Initialize SDL_ttf
                //if (TTF_Init() == -1)
                //{
                //    printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
                //    success = false;
                //}
            }
        }
    }

    return success;
}
#pragma endregion

//								Load data
/*****************************************************************************/
#pragma region Load data

LTexture* GraphicsManager::LoadTexture(std::string filePath)
{
    //Check if it exists
    for (int i = 0; i < textures.size(); i++) {
        if (textures[i]->getFilePath() == filePath) {
            return textures[i];
        }
    }

    //If not, create it
    LTexture* texture = new LTexture();
    texture->setFilePath(filePath);

    if (texture->loadFromFile(filePath)) {
        textures.push_back(texture);
        return textures[textures.size() - 1];
    }
    else {
        printf("\n\nUnable to load texture from file.\n\n");
        return NULL;
    }
}

#pragma endregion

//								Main function
/*****************************************************************************/
#pragma region Main function

void GraphicsManager::Render()
{
    for (int i = 0; i < SceneManager::GetInstance().GetCurrentScene()->GetObjectsInScene().size(); i++)
    {
        Object* obj = SceneManager::GetInstance().GetCurrentScene()->GetObject(i);

        SDL_Rect* size = new SDL_Rect();
        size->w = obj->GetWidth();
        size->h = obj->GetHeight();
        obj->GetTexture()->render(obj->GetX(), obj->GetY(), size);
        delete(size);
        size = NULL;
        
    }
}
#pragma endregion

//								Getters
/*****************************************************************************/
#pragma region Getters

SDL_Window* GraphicsManager::GetWindow()
{
    return mWindow;
}

SDL_Renderer* GraphicsManager::GetRenderer()
{
    return mRenderer;
}
#pragma endregion

/*****************************************************************************/
