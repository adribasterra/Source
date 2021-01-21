#include "Sound.h"

//							Constructors
/*****************************************************************************/
#pragma region Constructors

Sound::Sound()
{
    gSound = NULL;
}

Sound::~Sound()
{
    Mix_FreeChunk(gSound);
}
#pragma endregion

//							Getters
/*****************************************************************************/
#pragma region Getters

std::string Sound::GetPath()
{
    return path;
}
#pragma endregion

//							Main functions
/*****************************************************************************/
#pragma region Main functions

Sound* Sound::LoadFromFile(std::string path)
{
    //Load sound
    gSound = Mix_LoadWAV(path.c_str());
    if (gSound == NULL)
    {
        printf("Failed to load %s sound effect! SDL_mixer Error: %s\n", path.c_str(), Mix_GetError());
        return NULL;
    }
    this->path = path;
    return this;
}
#pragma endregion

//							Handle audio
/*****************************************************************************/
#pragma region Handle audio

void Sound::Play()
{
    Mix_PlayChannel(-1, gSound, 0);
}
#pragma endregion

/*****************************************************************************/