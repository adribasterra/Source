#include "Sound.h"

//							Constructors
/*****************************************************************************/

Sound::Sound()
{
    gSound = NULL;
}

Sound::~Sound()
{
    free(gSound);
}

//								Getters
/*****************************************************************************/

std::string Sound::GetPath()
{
    return path;
}

//							Main functions
/*****************************************************************************/

bool Sound::LoadFromFile(std::string path)
{
    //Load sound
    gSound = Mix_LoadWAV(path.c_str());
    if (gSound == NULL)
    {
        printf("Failed to load %s sound effect! SDL_mixer Error: %s\n", path.c_str(), Mix_GetError());
        return false;
    }
    this->path = path;
    return true;
}

void Sound::Play()
{
    Mix_PlayChannel(-1, gSound, 0);
}