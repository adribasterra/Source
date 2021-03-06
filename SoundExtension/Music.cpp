#include "Music.h"

//							Constructors
/*****************************************************************************/
#pragma region Constructors

Music::Music()
{
    gMusic = NULL;
}

Music::~Music()
{
    Mix_FreeMusic(gMusic);
}
#pragma endregion

//							Getters
/*****************************************************************************/
#pragma region Getters

std::string Music::GetPath()
{
    return path;
}
#pragma endregion

//							Main functions
/*****************************************************************************/
#pragma region Main functions

Music* Music::LoadFromFile(std::string path)
{
    //Load music
    gMusic = Mix_LoadMUS(path.c_str());
    if (gMusic == NULL)
    {
        printf("Failed to load %s music! SDL_mixer Error: %s\n", path.c_str(), Mix_GetError());
        return NULL;
    }
    this->path = path;
    return this;
}
#pragma endregion

//							Handle audio
/*****************************************************************************/
#pragma region Handle audio

void Music::Play()
{
    //If there is no music playing
    if (Mix_PlayingMusic() == 0)
    {
        //Play the music
        Mix_PlayMusic(gMusic, -1);
    }
    //If music is being played
    else
    {
        //If the music is paused
        if (Mix_PausedMusic() == 1)
        {
            //Resume the music
            Mix_ResumeMusic();
        }
        //If the music is playing
        else
        {
            //Pause the music
            Mix_PauseMusic();
        }
    }
}

void Music::Pause()
{
    if (Mix_PlayingMusic() != 0)
    {
        //Pause the music
        Mix_PauseMusic();
    }
}

void Music::Stop()
{
    //Stop the music
    Mix_HaltMusic();
}
#pragma endregion

/*****************************************************************************/