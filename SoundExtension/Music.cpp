#include "Music.h"

//							Constructors
/*****************************************************************************/

Music::Music()
{
    gMusic = NULL;
}

Music::~Music()
{
    free(gMusic);
}

//								Getters
/*****************************************************************************/

std::string Music::GetPath()
{
    return path;
}

//							Main functions
/*****************************************************************************/

bool Music::LoadFromFile(std::string path)
{
    //Load sound
    gMusic = Mix_LoadMUS(path.c_str());
    if (gMusic == NULL)
    {
        printf("Failed to load %s music! SDL_mixer Error: %s\n", path.c_str(), Mix_GetError());
        return false;
    }
    this->path = path;
    return true;
}

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

/*****************************************************************************/