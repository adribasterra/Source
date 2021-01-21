#include "Sound.h"

//							Constructors
/*****************************************************************************/

Sound::Sound()
{
    gSound = NULL;
}

Sound::~Sound()
{
    Mix_FreeChunk(gSound);
}

//							  Getters
/*****************************************************************************/

std::string Sound::GetPath()
{
    return path;
}

//							Main functions
/*****************************************************************************/

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

void Sound::Play()
{
    Mix_PlayChannel(-1, gSound, 0);
}

/*****************************************************************************/